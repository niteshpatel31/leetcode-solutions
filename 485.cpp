#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <vector>

class Solution {
public:
  const int
  findMaxConsecutiveOnes(const std::vector<int> &nums) const noexcept {
    int max{0}, cur{0};
    for (const int e : nums) {
      if (e == 0) {
        if (max < cur)
          max = cur;
        cur = 0;
        continue;
      }
      ++cur;
      fmt::println("cur : {}", cur);
    }
    return (max > cur) ? max : cur;
  }
};

int main(const int argc, const char *argv[]) {
  Solution sl;
  const std::vector<int> v1{1, 1, 0, 1, 1, 1}, v2{1, 0, 1, 1, 0, 1};
  fmt::println("{}", sl.findMaxConsecutiveOnes(v1));
  fmt::println("{}", sl.findMaxConsecutiveOnes(v2));
  return EXIT_SUCCESS;
}
