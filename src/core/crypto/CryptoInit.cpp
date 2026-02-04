#include "CryptoInit.hpp"
#include <sodium.h>
#include <stdexcept>

namespace crypto {
  void CryptoInit::init() {
    if (sodium_init() < 0) {
      throw new std::runtime_error("Failed to initialize libsodium");
    }
  }
}