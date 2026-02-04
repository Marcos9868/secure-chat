#include "KeyPair.hpp"
#include <sodium.h>

namespace crypto {

  KeyPair KeyPair::generate() {
    KeyPair kp;

    crypto_sign_keypair(
        kp.m_publicKey.data(),
        kp.m_privateKey.data()
    );

    return kp;
  }

  const KeyPair::PublicKey& KeyPair::publicKey() const {
    return m_publicKey;
  }

  const KeyPair::PrivateKey& KeyPair::privateKey() const {
    return m_privateKey;
  }

}
