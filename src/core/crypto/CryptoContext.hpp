#pragma once

namespace crypto {
  class CryptoContext {
    CryptoContext();
    ~CryptoContext() = default;

    CryptoContext(const CryptoContext&) = delete;
    CryptoContext& operator=(const CryptoContext&) = delete;
  };
}