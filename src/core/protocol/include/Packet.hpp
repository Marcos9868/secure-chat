#pragma once

namespace protocol {
  enum class PacketType : uint8_t {
    HANDSHAKE_INIT = 0x01,
    HANDSHAKE_RESPONSE = 0x02,
    MESSAGE = 0x03,
    ACK = 0x04
  };
}