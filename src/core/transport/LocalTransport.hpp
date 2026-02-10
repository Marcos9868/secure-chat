#pragma once

#include "ITransport.hpp"
#include <queue>
#include <mutex>

namespace transport {
  class LocalTransport : public ITransport {
  public:
    bool connect() override;
    bool send(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> receive() override;
    void close() override;

  private:
    bool m_connected{false};
    std::queue<std::vector<uint8_t>> m_queue;
    std::mutex m_mutex;
  };
}