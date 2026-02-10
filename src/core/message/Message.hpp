#pragma once

#include <string>
#include <cstdint>

namespace message {
  class Message {
    public:
      Message(
        std::string senderId,
        std::string receiverId,
        std::string payload,
        std::uint64_t timestamp
      );

      const std::string& senderId() const;
      const std::string& receiverId() const;
      const std::string& payload() const;
      std::uint64_t timestamp() const;

    private:
      std::string m_senderId;
      std::string m_receiverId;
      std::string m_payload;
      std::uint64_t m_timestamp;
  };
}