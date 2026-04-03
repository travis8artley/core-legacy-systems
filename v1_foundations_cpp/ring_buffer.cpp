#include <array>
#include <cstddef>

template <typename T, std::size_t N>
class RingBuffer {
 public:
  bool push(const T& value) {
    if (size_ == N) return false;
    data_[(head_ + size_) % N] = value;
    ++size_;
    return true;
  }

  bool pop(T& out) {
    if (size_ == 0) return false;
    out = data_[head_];
    head_ = (head_ + 1) % N;
    --size_;
    return true;
  }

 private:
  std::array<T, N> data_{};
  std::size_t head_ = 0;
  std::size_t size_ = 0;
};
