#pragma once
#include <vector>
#include <array>
#include <cstdint>

namespace crypto {

  class Signature
  {
    public:
      static constexpr size_t SIGNATURE_SIZE = 64;
      using SignatureBytes = std::array<uint8_t, SIGNATURE_SIZE>;

      static SignatureBytes sign(
        const std::vector<uint8_t> &message,
        const std::array<uint8_t, 64> &privateKey);

      static bool verify(
        const std::vector<uint8_t> &message,
        const SignatureBytes &signature,
        const std::array<uint8_t, 32> &publicKey);
  };

}
