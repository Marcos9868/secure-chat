#include <sodium.h>
#include <iostream>

int main() {
  if (sodium_init() < 0) {
    std::cerr << "libsodium initialization failed" << std::endl;
    return 1;
  }

  std::cout << "Secure Chat core initialized";
  return 0;
}