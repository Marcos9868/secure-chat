#pragma once
#include <array>
#include <cstdint>
#include <cstddef>

namespace crypto {
  class KeyPair {
    public:
      static constexpr size_t PUBLIC_KEY_SIZE = 32;
      static constexpr size_t PRIVATE_KEY_SIZE = 64;

      using PublicKey = std::array<uint8_t, PUBLIC_KEY_SIZE>;
      using PrivateKey = std::array<uint8_t, PRIVATE_KEY_SIZE>;

      static KeyPair generate();

      const PublicKey& publicKey() const;
      const PrivateKey& privateKey() const;

    private:
      PublicKey m_publicKey{};
      PrivateKey m_privateKey{};
  };
}