// 8. string to Integer (atoi)

#include <bits/stdc++.h>
#include <climits>
#include <fmt/format.h>

class Solution {
public:
  int myAtoi(const std::string &s) const noexcept {
    int64_t ans{0};
    bool sign{false}, digit{false}, negative{false};

    for (const char c : s) {
      if ((c == '-' || c == '+') && !digit && !sign) {
        sign = true;
        if (c == '-')
          negative = true;
      } else if (c == ' ' && !digit && !sign)
        continue;
      else if (c >= '0' && c <= '9') {
        digit = true;
        ans *= 10;
        ans += c - 48;
      } else
        break;

      if (ans >= INT_MAX || ans <= INT_MIN)
        break;
    }

    if (negative)
      ans *= -1;
    if (ans > INT_MAX)
      return INT_MAX;
    if (ans < INT_MIN)
      return INT_MIN;
    return ans;
  }
};

int main() {
  Solution sl;
  std::string s1{"42"}, s2{"   -042"}, s3{"1337c0d3"}, s4{"0-1"},
      s5{"words and 987"}, s6{"+-12"}, s7{"+1"};
  fmt::println("s: {0}, ans : {1}", s1, sl.myAtoi(s1));
  fmt::println("s: {0}, ans : {1}", s2, sl.myAtoi(s2));
  fmt::println("s: {0}, ans : {1}", s3, sl.myAtoi(s3));
  fmt::println("s: {0}, ans : {1}", s4, sl.myAtoi(s4));
  fmt::println("s: {0}, ans : {1}", s5, sl.myAtoi(s5));
  fmt::println("s: {0}, ans : {1}", s6, sl.myAtoi(s6));
  fmt::println("s: {0}, ans : {1}", s7, sl.myAtoi(s7));
}
