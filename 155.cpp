#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <vector>

class MinStack {
private:
  int min{2147483647};
  int topIdx{-1};
  std::vector<int> stack{std::vector<int>(1000, 0)};

  void shiftMin() {
    this->min = 2147483647;
    for (int i = 0; i < topIdx; i++)
      if (this->min > stack[i])
        this->min = stack[i];

    return;
  }

public:
  MinStack() {}

  void push(const int &val) {
    topIdx++;
    if (val < this->min)
      this->min = val;
    stack[topIdx] = val;
  }

  void pop() {
    if (this->min == stack[topIdx])
      shiftMin();
    topIdx--;
  }

  int top() { return this->stack[topIdx]; }

  int getMin() { return this->min; }
};

int main(int argc, const char *argv[]) {
  MinStack *stack = new MinStack();
  stack->push(-2);
  stack->push(0);
  stack->push(-3);
  fmt::println("{}", stack->getMin());
  stack->pop();
  fmt::println("{}", stack->top());
  fmt::println("{}", stack->getMin());
  return EXIT_SUCCESS;
}
