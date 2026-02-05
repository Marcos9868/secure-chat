#pragma once

#include <array>
#include <string>
#include <cstdint>

namespace identity {
  class Fingerprint {
    public:
      using PublicKey = std::array<uint8_t, 32>;

      static std::string fromPublicKey(const PublicKey& publicKey);
  };
}