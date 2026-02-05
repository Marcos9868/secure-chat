#include <sodium.h>
#include <iostream>
#include "core/crypto/CryptoInit.hpp"
#include "core/crypto/KeyPair.hpp"
#include "core/identity/identity.hpp"

int main() {
  crypto::CryptoInit::init();

  auto kp = crypto::KeyPair::generate();
  identity::Identity id(kp.publicKey());

  std::cout << "User ID: " << id.userId() << std::endl;
  std::cout << "Fingerprint: " << id.fingerprint() << std::endl;
  std::cout << "Secure Chat core initialized";
  return 0;
}