#include "heap.cpp"
#include <cstdlib>

template <typename T> class PriorityQueue {
private:
  Heap<T> queue;

public:
  PriorityQueue() {}
  PriorityQueue(const T &data) { insert(data); }

  void insert(const T &data) { queue.insert(data); }
  const T extractMax() { return queue.extractMax(); }
  const T &peek() const { return this->queue.peek(); }
  const T &size() const { return queue.size(); }
  void print() { queue.print(); }
};

int main(int argc, const char *argv[]) {
  PriorityQueue<int> pq;
  pq.insert(10);
  pq.insert(20);
  pq.insert(30);
  pq.insert(15);
  pq.insert(25);
  pq.insert(5);
  fmt::println("root -> {0}", pq.peek());
  fmt::println("max -> {0}", pq.peek());
  pq.print();
  return EXIT_SUCCESS;
}
