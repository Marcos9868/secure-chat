#include "CryptoContext.hpp"
#include <sodium.h>
#include <stdexcept>

namespace crypto {
  CryptoContext::CryptoContext() {
    static bool initialized = false;

    if (!initialized) {
      if (sodium_init()) {
        throw std::runtime_error("libsodium initialization failed");
      }
      initialized = true;
    }
  };
}