#pragma once
#include <vector>
#include "Packet.hpp"

namespace protocol {
  class Packet {
    public:
      Packet(PacketType type, std::vector<uint8_t> payload);

      PacketType type() const;
      const std::vector<uint8_t>& payload() const;

      std::vector<uint8_t> serialize() const;
      static Packet deserialize(const std::vector<uint8_t>& data);
    private:
      PacketType m_type;
      std::vector<uint8_t> m_payload;
  };
}