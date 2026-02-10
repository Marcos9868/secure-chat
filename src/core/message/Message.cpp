#include "Message.hpp"

namespace message {
  Message::Message(
    std::string senderId,
    std::string receiverId,
    std::string payload,
    std::uint64_t timestamp
  )
    : m_senderId(std::move(senderId)),
      m_receiverId(std::move(receiverId)),
      m_payload(std::move(payload)),
      m_timestamp(timestamp) {}

  const std::string& Message::senderId() const {
    return m_senderId;
  }

  const std::string& Message::receiverId() const {
    return m_receiverId;
  }

  const std::string& Message::payload() const {
    return m_payload;
  }

  std::uint64_t Message::timestamp() const {
    return m_timestamp;
  }
}