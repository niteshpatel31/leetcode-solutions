#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
class Solution {
public:
  [[gnu::always_inline]] inline int
  minRotations(const std::string &s) const noexcept {
    int rotations{};
    char prev{s[0]};
    for (const char ch : s) {
      const int clock{10 + prev - ch}, anti_clock{std::abs(prev - ch)};
      rotations += std::min(clock, anti_clock);
      fmt::println("rot:{0}, min:{1}, prev:{2}, ch:{3}", rotations,
                   std::min(clock, anti_clock), prev, ch);
      prev = ch;
    }
    fmt::println("rotations : {}", rotations);
    return rotations;
  }
};

int main() {
  Solution sl;
  sl.minRotations("0192837465");
  // sl.minRotations("1200210200");
  return EXIT_SUCCESS;
}
