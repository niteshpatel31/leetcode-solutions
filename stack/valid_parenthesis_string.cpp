#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
public:
  bool checkValidString(const std::string &s) {
    size_t stars{}, unres{s.size()}, idx{};
    for (size_t i{}; i < s.size(); ++i) {
      if (s[i] == '*')
        ++stars;
      else if (!s.empty() && s[idx] == '(' && s[i] == ')') {
        unres -= 2;
        while (idx <= s.size() && idx <= i + 1)
          if (s[idx] == '(')
            break;
          else
            ++idx;

      } else
        continue;
    }
    unres -= stars;
    return (unres <= stars);
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.checkValidString("()"));
  fmt::println("{}", sl.checkValidString("(*)"));
  fmt::println("{}", sl.checkValidString("(*))"));
  return EXIT_SUCCESS;
}
