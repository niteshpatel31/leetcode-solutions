#include <bits/stdc++.h>
#include <fmt/format.h>

class Solution {
public:
  int calPoints(const std::vector<std::string> &operations) const noexcept {
    int sum{}, tp1{}, tp2{};
    std::vector<int> v;

    for (const auto &s : operations) {
      switch (s[0]) {
      case 'C':
        v.pop_back();
        break;
      case 'D':
        v.emplace_back(v[v.size() - 1] * 2);
        break;
      case '+':
        tp1 = v[v.size() - 1];
        v.pop_back();
        tp2 = v[v.size() - 1];
        v.emplace_back(tp1);
        v.emplace_back(tp1 + tp2);
        break;
      default:
        v.emplace_back(std::stoi(s));
      }
    }
    for (const int x : v)
      sum += x;
    return sum;
  }
};

int main() {
  Solution sl;
  const std::vector<std::string> v1{"5", "2", "C", "D", "+"},
      v2{"5", "-2", "4", "C", "D", "9", "+", "+"}, v3{"1", "C"},
      v4{"36", "28", "70", "65", "C", "+", "33", "-46", "84", "C"};
  fmt::println("point : {}", sl.calPoints(v1));
  fmt::println("point : {}", sl.calPoints(v2));
  fmt::println("point : {}", sl.calPoints(v3));
  fmt::println("point : {}", sl.calPoints(v4));
  return EXIT_SUCCESS;
}
