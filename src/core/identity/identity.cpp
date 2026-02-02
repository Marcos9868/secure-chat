#include "identity.h"
#include <sodium.h>
#include <stdexcept>

Identity Identity::Create() {
  Identity id;

  id.public_key_.resize(crypto_sign_PUBLICKEYBYTES);
  id.private_key_.resize(crypto_sign_SECRETKEYBYTES);

  if (crypto_sign_keypair(id.public_key_.data(), id.private_key_.data()) != 0) {
    throw std::runtime_error("Failed to generate keypair");
  }

  return id;
};

const std::vector<uint8_t>& Identity::public_key() const {
  return public_key_;
}

std::vector<uint8_t> Identity::sign(const std::vector<uint8_t>& data) const {
  std::vector<uint8_t> signature(crypto_sign_BYTES);

  crypto_sign_detached(
    signature.data(),
    nullptr,
    data.data(),
    data.size(),
    private_key_.data()
  );

  return signature;
};
