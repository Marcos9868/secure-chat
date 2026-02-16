#include "handshake/HandshakeManager.hpp"
#include "protocol/PacketType.hpp"

#include <sodium.h>
#include <stdexcept>

namespace handshake
{

  HandshakeManager::HandshakeManager(
      identity::Identity &identity,
      SendFunction sender)
      : m_identity(identity),
        m_sender(std::move(sender))
  {
  }

  void HandshakeManager::initiate()
  {
    // Envia nossa public key
    protocol::Packet packet(
        protocol::PacketType::HANDSHAKE_INIT,
        m_identity.getPublicKey());

    m_sender(packet);
  }

  void HandshakeManager::handlePacket(const protocol::Packet &packet)
  {
    switch (packet.type())
    {
    case protocol::PacketType::HANDSHAKE_INIT:
      handleInit(packet);
      break;

    case protocol::PacketType::HANDSHAKE_RESPONSE:
      handleResponse(packet);
      break;

    default:
      break;
    }
  }

  void HandshakeManager::handleInit(const protocol::Packet &packet)
  {
    // Recebe public key do peer
    const auto &remotePubKey = packet.payload();

    deriveSharedKey(remotePubKey);

    // Responde com nossa public key
    protocol::Packet response(
        protocol::PacketType::HANDSHAKE_RESPONSE,
        m_identity.getPublicKey());

    m_sender(response);

    m_complete = true;
  }

  void HandshakeManager::handleResponse(const protocol::Packet &packet)
  {
    const auto &remotePubKey = packet.payload();

    deriveSharedKey(remotePubKey);

    m_complete = true;
  }

  void HandshakeManager::deriveSharedKey(const std::vector<uint8_t> &remotePubKey)
  {
    if (remotePubKey.size() != crypto_kx_PUBLICKEYBYTES)
    {
      throw std::runtime_error("Invalid public key size in handshake");
    }

    std::vector<uint8_t> rx(crypto_kx_SESSIONKEYBYTES);
    std::vector<uint8_t> tx(crypto_kx_SESSIONKEYBYTES);

    if (crypto_kx_client_session_keys(
            rx.data(),
            tx.data(),
            m_identity.getPublicKey().data(),
            m_identity.getPrivateKey().data(),
            remotePubKey.data()) != 0)
    {
      throw std::runtime_error("Failed to derive session keys");
    }

    // Para simplificar, usamos tx como session key
    m_sessionKey = tx;
  }

  bool HandshakeManager::isComplete() const
  {
    return m_complete;
  }

  const std::vector<uint8_t> &HandshakeManager::sessionKey() const
  {
    return m_sessionKey;
  }

}
