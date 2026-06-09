#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/printf.h>

void println(const std::vector<int> &v) {
  for (const int x : v)
    fmt::print("{}, ", x);
  fmt::println("");
  return;
}

class Solution {
public:
  std::vector<int>
  dailyTemperatures(const std::vector<int> &temp) const noexcept {
    std::vector<int> ans;
    int day{};
    ans.reserve(temp.size());
    for (size_t i{0}; i < temp.size(); i++) {
      day = 0;
      for (size_t j{i + 1}; j < temp.size(); j++) {
        if (temp[j] > temp[i]) {
          day = j - i;
          break;
        }
      }
      ans.emplace_back(day);
    }
    return ans;
  }
};

int main(int argc, const char *argv[]) {
  Solution sl;
  const std::vector<int> v1{73, 74, 75, 71, 69, 72, 76, 73}, v2{30, 40, 50, 60},
      v3{30, 60, 90};
  println(sl.dailyTemperatures(v1));
  println(sl.dailyTemperatures(v2));
  println(sl.dailyTemperatures(v3));
  return EXIT_SUCCESS;
}
