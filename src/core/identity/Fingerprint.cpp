#include "Fingerprint.hpp"
#include <sodium.h>
#include <sstream>
#include <iomanip>

namespace identity {
  std::string Fingerprint::fromPublicKey(const PublicKey& publicKey) {
    std::array<uint8_t, crypto_generichash_BYTES> hash{};

    crypto_generichash(
      hash.data(),
      hash.size(),
      publicKey.data(),
      publicKey.size(),
      nullptr,
      0
    );

    std::ostringstream oss;
    for (size_t i = 0; i < 8; ++i) {
      if (i > 0 && i % 2 == 0) oss << "-";
      oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return oss.str();
  }
}