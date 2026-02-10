#include <sodium.h>
#include <iostream>
#include <ctime>
#include "core/crypto/CryptoInit.hpp"
#include "core/crypto/KeyPair.hpp"
#include "core/identity/identity.hpp"
#include "core/message/Message.hpp"
#include "core/transport/LocalTransport.hpp"

int main() {
  /*crypto::CryptoInit::init();

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
  std::cout << "Payload: " << msg.payload() << "\n";*/
  transport::LocalTransport transport;

  transport.connect();

  std::vector<uint8_t> message = { 'H', 'e', 'l', 'l', 'o' };
  transport.send(message);

  auto received = transport.receive();

  std::cout << "Received bytes: ";
  for (auto c : received) {
    std::cout << static_cast<char>(c);
  }
  std::cout << std::endl;

  transport.close();
  return 0;
}