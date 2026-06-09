#include <bits/stdc++.h>
#include <fmt/format.h>

class Solution {
public:
  std::string convertToTitle(int col) const noexcept {
    std::string s;
    s.reserve(7);
    while (col > 0) {
      s.push_back(col / 26 + 65);
      col /= 26;
    }
    if (col > 0)
      s.push_back(col %26 + 65);
    std::reverse(s.begin(), s.end());
    return s;
  }
};

int main(int argc, const char *argv[]) {
  Solution sl;
  fmt::println("{}", sl.convertToTitle(701));
  fmt::println("{}", sl.convertToTitle(28));
  fmt::println("{}", sl.convertToTitle(1));
  return EXIT_SUCCESS;
}
bool isPerfectSquare(int num) {
    //Newton-Rapshon Method
   long x = num;
    while (x * x > num) {
        x = (x + (num / x)) / 2;
    }
    if ((x * x) == num) {
        return true;
    } else {
        return false;
    }
}  
