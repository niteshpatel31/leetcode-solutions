#include <cstdlib>
#include <fmt/base.h>
#include <unordered_set>
#include <vector>
class Solution {
public:
  const int longestConsecutive(const std::vector<int> &nums) const noexcept {
    if (nums.size() < 2)
      return static_cast<int>(nums.size());
    std::unordered_set<int> set(nums.begin(), nums.end());
    int max{1}, cur{1}, temp{};
    for (const auto &e : set)
      if (set.find(e - 1) == set.end()) {
        temp = e;

        while (set.find(temp + 1) != set.end()) {
          ++cur;
          ++temp;
        }

        if (max < cur)
          max = cur;
        cur = 1;
      }

    return max;
  }
};

int main(int argc, const char *argv[]) {
  Solution sol;
  std::vector<int> v1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, v2{1, 0, 1, 2},
      v3{100, 4, 200, 1, 3, 2}, v4{100, 4, 200, 1, 3, 2}, v5{2, 1},
      v6{0, 0, -1}, v7{}, v8{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v1));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v2));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v3));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v4));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v5));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v6));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v7));
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v8));
  return EXIT_SUCCESS;
}
