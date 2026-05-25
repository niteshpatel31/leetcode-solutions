#include <cstdlib>
#include <fmt/format.h>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(const std::string &s) {
    unsigned int max{}, cur{};
    std::unordered_set<char> set;
    set.reserve(26);
    for (auto &c : s) {
      if (set.count(c)) {
        set.clear();
        if (max < cur)
          max = cur;
        cur = 0;
      }
      ++cur;
      set.insert(c);
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  std::string s1{"abcabcbb"}, s2{"bbbbb"}, s3{"pwwkew"}, s4{"au"};
  Solution sl;
  fmt::println("{}", sl.lengthOfLongestSubstring(s4));
  return EXIT_SUCCESS;
}
