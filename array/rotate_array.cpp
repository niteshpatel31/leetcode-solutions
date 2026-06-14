#include <bits/stdc++.h>
#include <fmt/format.h>

void println(const std::vector<int> &v) noexcept {
  for (const int e : v)
    fmt::print("{}, ", e);
  fmt::println("");
  return;
}

class Solution {
public:
  void rotate(std::vector<int> &nums, int k) const noexcept {
    if (nums.size() < 2)
      return;
    nums.reserve(nums.size() + k);
    int size{static_cast<int>(nums.size())}, temp{k};
    k = size - k;
    while (k < size) {
      nums.emplace(nums.begin(), nums[nums.size() - k]);
      k += 2;
    }
    if (temp % 2)
      nums.emplace(nums.begin(), nums[nums.size() - 1u]);
    temp = (temp % 2) ? temp : temp - 1;
    nums.erase(nums.end() - temp, nums.end());
    return;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7}, v2{-1, -100, 3, 99};
  sl.rotate(v1, 3);
  println(v1);
  sl.rotate(v2, 2);
  println(v2);
}
