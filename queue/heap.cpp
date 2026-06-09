#include "../common/vector.cpp"
#include <cstdint>
#include <fmt/base.h>
#include <fmt/format.h>
#include <stdexcept>
#include <utility>

// Priority queue is an ADT implemented usaully through binary heap.

/*
   Heap: its a complete binary tree
   parent(i) -> i/2
   left(i) -> i*2
   right(i) -> i*2+1 , where i is idx

*/

template <class T> class Heap {
private:
  vector<T> heap;
  int mx;

  uint64_t parent(const int64_t &idx) const noexcept { return idx / 2; }
  uint64_t left(const int64_t &idx) const noexcept { return idx * 2; }
  uint64_t right(const int64_t &idx) const noexcept { return idx * 2 + 1; }

  void shift(const int64_t &i) noexcept {
    int64_t idx{i};
    while (idx > 0 && heap[idx] > heap[parent(idx)]) {
      std::swap(heap[idx], heap[parent(idx)]);
      idx = parent(idx);
    }
  }

public:
  Heap() {}
  Heap(const T &data) { insert(data); }

  const T &peek() const {
    if (heap.size() > 0)
      return heap[0];
    else
      throw std::runtime_error("HEAP is not Initialized");
  }

  const size_t size() const { return heap.size(); }

  void insert(const T &data) {
    heap.push_back(data);
    shift(heap.size() - 1);
  }

  const T extractMax() {
    if (heap.size() < 1)
      throw std::runtime_error("HEAP UNDERFLOW");
    T max = peek();
    heap[0] = heap[heap.size() - 1];
    shift(heap.size() - 1);
    return max;
  }

  void increaseKey() {}

  void print() {
    for (auto &c : heap)
      fmt::print("{0}, ", c);
    fmt::println("");
    return;
  }
};
