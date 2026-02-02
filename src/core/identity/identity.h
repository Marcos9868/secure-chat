#pragma once

#include <vector>
#include <cstdint>

class Identity {
  public:
    static Identity Create();

    const std::vector<uint8_t>& public_key() const;
    std::vector<uint8_t> sign(const std::vector<uint8_t>& data) const;
  private:
    std::vector<uint8_t> public_key_;
    std::vector<uint8_t> private_key_;
};