#include <cstdlib>
#include <fmt/format.h>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(const std::string &s) {
    unsigned int max{}, cur{};
    std::unordered_map<char, int> map;
    map.reserve(26);
    for (int i{0}; i < static_cast<int>(s.size()) - 1; i++) {
      const char c{s[i]};
      ++cur;
      if (map.find(c) != map.end()) {
        i = map.find(c)->second + 1;
        map.erase(c);
        if (cur > max)
          max = cur;
        cur = 0;
      } else
        map.insert({c, i});
    }
    return max;
  }
};

int main() {
  std::string s1{"abcabcbb"}, s2{"bbbbb"}, s3{"pwwkew"}, s4{"dvdf"}, s5{"au"},
      s6{" "};
  Solution sl;
  fmt::println("{1} : {0}", s1, sl.lengthOfLongestSubstring(s1));
  fmt::println("{1} : {0}", s2, sl.lengthOfLongestSubstring(s2));
  fmt::println("{1} : {0}", s3, sl.lengthOfLongestSubstring(s3));
  fmt::println("{1} : {0}", s4, sl.lengthOfLongestSubstring(s4));
  fmt::println("{1} : {0}", s5, sl.lengthOfLongestSubstring(s5));
  fmt::println("{1} : {0}", s6, sl.lengthOfLongestSubstring(s6));
  return EXIT_SUCCESS;
}
