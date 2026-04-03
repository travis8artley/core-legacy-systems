#include <cassert>
#include <cstdint>
#include <iostream>

#include "../src/allocators/arena_allocator.h"

int main() {
  std::uint8_t buffer[256] = {};
  ArenaAllocator arena(buffer, sizeof(buffer));

  void* a = arena.allocate(32, 8);
  void* b = arena.allocate(64, 16);
  void* c = arena.allocate(512, 8);

  assert(a != nullptr);
  assert(b != nullptr);
  assert(c == nullptr);
  assert(arena.used() > 0);

  arena.reset();
  assert(arena.used() == 0);

  std::cout << "arena_allocator_test: ok\n";
  return 0;
}
