#include <cstdlib>
#include <iostream>
#include <vector>

constexpr char endl = '\n';

class Solution {
public:
  int maxArea(const std::vector<int> &height) const noexcept {
    size_t i{0}, j{height.size() - 1}, left{i}, right{j};
    int max{}, lt{}, rt{};
    while (i < j) {
      lt = std::min(height[left], height[j]) * j - left;
      rt = std::min(height[i], height[right]) * right - i;
      std::cout << "lt : " << lt << endl;
      std::cout << "rt : " << rt << endl;
      if (lt > rt) {
        right = j;
        if (lt > max)
          max = lt;
      } else {
        left = i;
        if (rt > max)
          max = rt;
      }
      ++i;
      --j;
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  std::vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7}, v2{1, 1};
  Solution sl;
  std::cout << sl.maxArea(v1) << endl;
  std::cout << sl.maxArea(v2) << endl;
  return EXIT_SUCCESS;
}
