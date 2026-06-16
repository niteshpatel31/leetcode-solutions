// 3612. Process String with Special Operations I

#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>

static std::string ans;

class Solution {
public:
  Solution() { ans.reserve(40); }

  std::string processStr(const std::string &s) const noexcept {
    ans.clear();

    for (const char c : s) {
      switch (c) {
      case '*':
        if (ans.size() > 0)
          ans.erase(ans.size() - 1);
        break;
      case '#':
        if (ans.size() > 0)
          ans += ans;
        break;
      case '%':
        if (ans.size() > 0)
          std::reverse(ans.begin(), ans.end());
        break;
      default:
        ans.push_back(c);
      }
    }
    return ans;
  }
};

int main() {
  Solution sl;
  const std::string s1{"a#b%*"}, s2{"z*#"};
  fmt::println("ans : {}", sl.processStr(s1));
  fmt::println("ans : {}", sl.processStr(s2));
  return EXIT_SUCCESS;
}
