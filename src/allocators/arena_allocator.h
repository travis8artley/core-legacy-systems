#pragma once

#include <cstddef>
#include <cstdint>
#include <new>

class ArenaAllocator {
 public:
  ArenaAllocator(std::uint8_t* buffer, std::size_t capacity)
      : buffer_(buffer), capacity_(capacity), offset_(0) {}

  void* allocate(std::size_t size, std::size_t alignment = alignof(std::max_align_t)) {
    std::size_t aligned = (offset_ + alignment - 1) & ~(alignment - 1);
    if (aligned + size > capacity_) return nullptr;
    void* ptr = buffer_ + aligned;
    offset_ = aligned + size;
    return ptr;
  }

  void reset() { offset_ = 0; }
  std::size_t used() const { return offset_; }

 private:
  std::uint8_t* buffer_;
  std::size_t capacity_;
  std::size_t offset_;
};
