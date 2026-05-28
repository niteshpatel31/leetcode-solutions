#include <cstdlib>
#include <fmt/format.h>
#include <vector>

constexpr char endl = '\n';

class Solution {
public:
  int maxArea(const std::vector<int> &height) const noexcept {
    size_t i{0}, j{height.size() - 1}, max{0}, cur{0};
    while (i < j) {
      cur = std::min(height[i], height[j]) * (j - i);
      // fmt::println("cur : {0}, i : {1}, j:{2}", cur, i, j);
      if (height[i] < height[j])
        ++i;
      else
        --j;
      if (max < cur)
        max = cur;
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  std::vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7}, v2{1, 1};
  Solution sl;
  fmt::println("{}", sl.maxArea(v1));
  fmt::println("{}", sl.maxArea(v2));
  return EXIT_SUCCESS;
}
