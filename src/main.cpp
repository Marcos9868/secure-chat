#include <sodium.h>
#include <iostream>
#include <ctime>
#include "core/crypto/CryptoInit.hpp"
#include "core/crypto/KeyPair.hpp"
#include "core/identity/identity.hpp"
#include "core/message/Message.hpp"

int main() {
  crypto::CryptoInit::init();

  auto kp = crypto::KeyPair::generate();
  identity::Identity id(kp.publicKey());

  message::Message msg(
    id.userId(),
    "receiver-id",
    "Hello Secure World",
    static_cast<std::uint64_t>(std::time(nullptr))
  );

  std::cout << "From: " << msg.senderId() << "\n";
  std::cout << "To: " << msg.receiverId() << "\n";
  std::cout << "Payload: " << msg.payload() << "\n";
 return 0;
}