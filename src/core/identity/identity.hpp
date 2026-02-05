#pragma once

#include <array>
#include <vector>
#include <cstdint>
#include <string>

namespace identity {
  class Identity {
    public:
      using PublicKey = std::array<uint8_t, 32>;
    
      explicit Identity(const PublicKey& publicKey);

      const PublicKey& publicKey() const;
      const std::string& fingerprint() const;
      const std::string& userId() const;

    private:
      PublicKey m_publicKey;
      std::string m_fingerprint;
      std::string m_userId;

      static std::string deriveUserId(const PublicKey& publicKey);
  };
}
