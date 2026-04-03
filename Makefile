CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic

.PHONY: test

test:
	$(CXX) $(CXXFLAGS) tests/arena_allocator_test.cpp -o tests/arena_allocator_test
	./tests/arena_allocator_test
