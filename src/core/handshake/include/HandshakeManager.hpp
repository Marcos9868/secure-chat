#pragma once

#include <vector>
#include <functional>
#include <memory>

#include "protocol/include/Packet.hpp"
#include "identity/identity.hpp"

namespace handshake {
  class HandshakeManager {
    public:
      using SendFunction = std::function<(const protocol::PacketType&)>;

      HandshakeManager(identity::Identity& identity, SendFunction sender);

      void initiate();
      void handlePacket(const protocol::PacketType packet);

      bool isComplete() const;
      const std::vector<uint8_t>& sessionKey() const;
    private:
      void handleInit(const protocol::PacketType& packet);
      void handleResponse(const protocol::PacketType& packet);
      void deriveSharedKey(const std::vector<uint8_t>& remotePubKey);
    private:
      identity::Identity& m_identity;
      SendFunction m_sender;
      bool m_complete = false;
      std::vector<uint8_t> m_sessionKey;
  };
}