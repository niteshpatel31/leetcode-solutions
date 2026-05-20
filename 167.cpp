#include <cstdlib>
#include <fmt/format.h>
#include <unordered_map>
#include <vector>

void print(const std::vector<int> &nums) {
  fmt::println("{0}, {1}", nums[0], nums[1]);
  return;
}

class Solution {
public:
  std::vector<int> twoSum1(const std::vector<int> &nums,
                           const int target) const noexcept {
    int size{(int)nums.size()}, i{}, complement{}, j{};
    std::unordered_map<int, int> mp;
    auto it = mp.find(nums[0]);
    for (; i < size; i++) {
      complement = target - nums[i];
      it = mp.find(complement);
      if (it != mp.end()) {
        j = it->second;
        return {++j, ++i};
      }
      mp.insert({nums[i], i});
    }
    return {++i, ++j};
  }

  std::vector<int> twoSum(const std::vector<int> &nums,
                          const int target) const noexcept {
    int i{}, j{(int)nums.size() - 1}, complement{};
    while (i < j) {
      complement = nums[i] + nums[j];
      if (complement == target)
        return {++i, ++j};
      else if (complement > target)
        --j;
      else
        ++i;
    }
    return {++i, ++j};
  }
};

int main(int argc, const char *argv[]) {
  Solution sl;
  std::vector<int> v1{2, 7, 11, 15}, v2{2, 3, 4}, v3{-1, 0};
  int t1{9}, t2{6}, t3{-1};
  print(sl.twoSum(v1, t1));
  print(sl.twoSum(v2, t2));
  print(sl.twoSum(v3, t3));
  return EXIT_SUCCESS;
}
