#include <fmt/format.h>

class Solution {
public:
  bool isPalindrome(std::string &s) {
    if (s.size() > 1ul) {
      size_t i{0ul}, j{0ul};
      for (; i < s.size(); i++) {
        if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0'))
          s[j++] = s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
          s[j++] = s[i] + 32;
        else {
        }
      }
      s.erase(s.begin() + j, s.end());
      if (1ul < s.size()) {
        for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
          if (s[i] != s[j]) {
            return false;
          }
        }
      }
    }

    return true;
  }
};

int main(int argc, const char *argv[]) {
  Solution sl;
  std::string s1{"A man, a plan, a canal: Panama"}, s3{" "}, s2{"race a car"},
      s4{"0P"}, s5{"a."};
  fmt::println("{}", sl.isPalindrome(s1));
  fmt::println("{}", sl.isPalindrome(s2));
  fmt::println("{}", sl.isPalindrome(s3));
  fmt::println("{}", sl.isPalindrome(s4));
  fmt::println("{}", sl.isPalindrome(s5));
  return EXIT_SUCCESS;
}
