#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
public:
  int totalNumbers(const std::vector<int> &digits) {
    int even{};
    for (const int x : digits) {
      if (x % 2 == 0)
        ++even;
    }
    const int n{static_cast<int>(digits.size())};
    return (n - 1) * (n - 2) * even;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 2, 3, 4}, v2{0, 2, 2}, v3{6, 6, 6}, v4{1, 3, 5},
      v5{1, 2, 3}, v6{1, 2, 3, 2, 7, 8, 0};
  fmt::println("ans : {}", sl.totalNumbers(v1));
  fmt::println("ans : {}", sl.totalNumbers(v2));
  fmt::println("ans : {}", sl.totalNumbers(v3));
  fmt::println("ans : {}", sl.totalNumbers(v4));
  fmt::println("ans : {}", sl.totalNumbers(v5));
  fmt::println("ans : {}", sl.totalNumbers(v6));
  return EXIT_SUCCESS;
}
