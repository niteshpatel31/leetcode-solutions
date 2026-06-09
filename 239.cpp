#include <cstdlib>
#include <fmt/printf.h>
#include <vector>

void println(const std::vector<int> &v) noexcept {
  for (const int e : v)
    fmt::print("{}, ", e);
  fmt::println("");
  return;
}

class Solution {
public:
  const std::vector<int> maxSlidingWindow(const std::vector<int> &nums,
                                          const int k) const noexcept {
    std::vector<int> ans;
    ans.reserve(nums.size());
    int i{0}, j{k - 1}, max{}, idx{};
    const int size{static_cast<int>(nums.size())};
    while (j < size) {
      idx = i -1  ;
      max = -2147483648;
      while (++idx <= j) {
        if (nums[idx] > max)
          max = nums[idx];
      }
      ans.emplace_back(max);
      ++i;
      ++j;
    }
    return ans;
  }
};

int main(const int argc, const char *argv[]) {
  Solution sl;
  const std::vector<int> v1{1, 3, -1, -3, 5, 3, 6, 7}, v2{1};
  println(sl.maxSlidingWindow(v1, 3));
  println(sl.maxSlidingWindow(v2, 1));
  return EXIT_SUCCESS;
}
