#include <algorithm>
#include <cstdlib>
#include <fmt/base.h>
#include <vector>

void println(const std::vector<std::vector<int>> &nums) noexcept {
  for (const auto &n : nums) {
    for (const int x : n)
      fmt::print("{}, ", x);
    fmt::println("");
  }
  fmt::println("");
  return;
}
void println(const std::vector<int> &n) noexcept {
  for (const int x : n)
    fmt::print("{} , ", x);
  fmt::println("");
  return;
}

class Solution {
public:
  std::vector<std::vector<int>>
  threeSum(std::vector<int> &nums) const noexcept {
    std::vector<std::vector<int>> ans;

    const size_t size = nums.size();
    size_t i{0}, j{i + 1}, k{size - 1};

    ans.reserve(size >> 1);
    std::sort(nums.begin(), nums.end());

    for (i = 0; i < size - 2; ++i) {
      const int ni{nums[i]};

      if (ni > 0 || nums[i] + nums[i + 1] + nums[i + 2] > 0)
        break;
      if ((i > 0 && ni == nums[i - 1]) ||
          ni + nums[size - 2] + nums[size - 1] < 0)
        continue;

      j = i + 1;
      k = size - 1;
      const int target{-ni};

      while (j < k) {
        const int sum{nums[j] + nums[k]};

        if (sum == target) [[unlikely]] {
          ans.push_back({ni, nums[j], nums[k]});

          while (j < k && nums[j] == nums[j + 1])
            ++j;
          while (j < k && nums[k] == nums[k - 1])
            --k;
          ++j;
          --k;
        } else {
          const int diff{sum - target};
          const int sign{diff >> 31};
          j -= sign;
          k += sign + 1;
        }
      }
    }
    return ans;
  }
};

int main(int argc, const char *argv[]) {
  Solution sl;
  std::vector<int> v1{-1, 0, 1, 2, -1, -4}, v2{0, 1, 1}, v3{0, 0, 0},
      v4{0, 0, 0, 0};
  println(sl.threeSum(v1));
  println(sl.threeSum(v2));
  println(sl.threeSum(v3));
  println(sl.threeSum(v4));
  return EXIT_SUCCESS;
}
