#include "LocalTransport.hpp"

namespace transport {

  bool LocalTransport::connect() {
    m_connected = true;
    return true;
  }

  bool LocalTransport::send(const std::vector<uint8_t>& data) {
    if (!m_connected) {
      return false;
    }

    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(data);
    return true;
  }

  std::vector<uint8_t> LocalTransport::receive() {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_queue.empty()) {
      return {};
    }

    auto data = m_queue.front();
    m_queue.pop();
    return data;
  }

  void LocalTransport::close() {
    m_connected = false;
    std::lock_guard<std::mutex> lock(m_mutex);
    while (!m_queue.empty()) {
      m_queue.pop();
    }
  }

}
