#include "identity.hpp"
#include "Fingerprint.hpp"

#include <sodium.h>
#include <sstream>
#include <iomanip>

namespace identity {

Identity::Identity(const PublicKey& publicKey)
    : m_publicKey(publicKey),
      m_fingerprint(Fingerprint::fromPublicKey(publicKey)),
      m_userId(deriveUserId(publicKey)) {}

const Identity::PublicKey& Identity::publicKey() const {
  return m_publicKey;
}

const std::string& Identity::fingerprint() const {
  return m_fingerprint;
}

const std::string& Identity::userId() const {
  return m_userId;
}

std::string Identity::deriveUserId(const PublicKey& publicKey) {
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
  for (auto b : hash) {
    oss << std::hex << std::setw(2)
        << std::setfill('0')
        << static_cast<int>(b);
  }

  return oss.str();
}

}
