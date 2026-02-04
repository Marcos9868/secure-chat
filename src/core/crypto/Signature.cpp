#include "Signature.hpp"
#include <sodium.h>

namespace crypto
{

  Signature::SignatureBytes Signature::sign(
      const std::vector<uint8_t> &message,
      const std::array<uint8_t, 64> &privateKey)
  {
    SignatureBytes signature{};
    unsigned long long sigLen = 0;

    crypto_sign_detached(
        signature.data(),
        &sigLen,
        message.data(),
        message.size(),
        privateKey.data());

    return signature;
  }

  bool Signature::verify(
      const std::vector<uint8_t> &message,
      const SignatureBytes &signature,
      const std::array<uint8_t, 32> &publicKey)
  {
    return crypto_sign_verify_detached(
               signature.data(),
               message.data(),
               message.size(),
               publicKey.data()) == 0;
  }

}