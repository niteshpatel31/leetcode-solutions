#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>

class Solution {
public:
  double angleClock(const double hour, const double minutes) const noexcept {
    const double hr{hour * 30};
    if (minutes == 0)
      return 0;
    double ans{(30 * minutes / 5) - (5 * (minutes / 10))};
    // fmt::println("hr : {0}, 360 : {1}", ans - hr, 360 - ans - hr);
    if (ans - hr < 0 && 360 - ans - hr < 0)
      return std::abs(std::max(ans - hr, 360 - ans - hr));
    else if (ans - hr < 0 || 360 - ans - hr < 0)
      return std::abs(ans - hr);
    else
      return std::abs(std::min(ans - hr, 360 - ans - hr));
  }
};

int main() {
  Solution sl;
  int minute{}, hour{}, cnt{1}, test{};
  std::cin >> test;
  while (test--) {
    std::cin >> hour;
    std::cin >> minute;
    fmt::println("{1} : {0}", sl.angleClock(hour, minute), cnt);
    ++cnt;
  }
  return EXIT_SUCCESS;
}
