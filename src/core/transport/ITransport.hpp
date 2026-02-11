#pragma once

#include <vector>
#include <cstdint>

namespace transport {
  class ITransport {
    public:
      virtual ~ITransport();

      virtual bool connect() = 0;
      virtual bool send(const std::vector<uint8_t>& data) = 0;
      virtual std::vector<uint8_t> receive() = 0;
      virtual void close() = 0;
  };
}