#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>

class Solution {
public:
  std::string lexGreaterPermutation(const std::string &s,
                                    const std::string &t) const noexcept {
    if (s.size() < 2)
      return (s.size() && s[0] > t[0]) ? s : "";
    std::array<int, 26> cnt{0};
    std::string ans;
    ans.reserve(t.size());

    for (const auto c : s)
      ++cnt[static_cast<int>(c) - 97];

    for (const auto c : t) {
      int idx{static_cast<int>(c) - 97};
      if (cnt[idx] == 0) {
        while (++idx < 26) {
          if (cnt[idx] > 0) {
            ans.push_back(static_cast<char>(idx + 97));
            --cnt[idx];
            break;
          }
        }
        break;
      } else {
        ans.push_back(c);
        --cnt[static_cast<int>(c) - 97];
      }
    }
    for (size_t i{0}; i < cnt.size(); i++) {
      while (cnt[i] > 0) {
        ans.push_back(static_cast<char>(i + 97));
        --cnt[i];
      }
    }

    return ans == t ? "" : ans;
  }
};

int main() {
  Solution sl;
  std::array<std::string, 2> a1{"abc", "bba"}, a2{"leet", "code"},
      a3{"baba", "bbaa"}, a4{"a", "b"}, a5{"aa", "ab"};
  fmt::println("{}", sl.lexGreaterPermutation(a1[0], a1[1]));
  fmt::println("{}", sl.lexGreaterPermutation(a2[0], a2[1]));
  fmt::println("{}", sl.lexGreaterPermutation(a3[0], a3[1]));
  fmt::println("{}", sl.lexGreaterPermutation(a4[0], a4[1]));
  fmt::println("{}", sl.lexGreaterPermutation(a3[0], a5[1]));
  return EXIT_SUCCESS;
}
