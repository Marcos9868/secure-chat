#include <sodium.h>
#include <iostream>
#include "core/crypto/CryptoInit.hpp"

int main() {
  crypto::CryptoInit::init();
  std::cout << "Secure Chat core initialized";
  return 0;
}