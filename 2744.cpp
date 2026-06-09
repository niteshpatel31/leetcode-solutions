#include <algorithm>
#include <fmt/format.h>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int maximumNumberOfStringPairs(
      std::vector<std::string> &words) const noexcept {
    std::unordered_set<std::string> set;
    uint32_t pairs{};

    for (auto &s : words) {
      if (set.find(s) != set.end())
        ++pairs;
      s[0] = s[1] + s[0];
      s[1] = s[0] - s[1];
      s[0] = s[0] - s[1];
      if (set.find(s) != set.end())
        ++pairs;
      set.insert(s);
    }
    return pairs;
  }
};

int main(const int argc, const char *argv[]) {
  Solution sl;
  std::vector<std::string> v1{"cd", "ac", "dc", "ca", "zz"},
      v2{"ab", "ba", "cc"}, v3{"aa", "ab"},
      v4{"xi", "nw", "qp", "to", "oo", "xp", "ix", "wn", "pq"},
      v5{"ny", "gz", "yr", "kt", "qd", "yn", "zg", "ry", "tk", "dq"};
  fmt::println("pairs :  {}", sl.maximumNumberOfStringPairs(v1));
  fmt::println("pairs :  {}", sl.maximumNumberOfStringPairs(v2));
  fmt::println("pairs :  {}", sl.maximumNumberOfStringPairs(v3));
  fmt::println("pairs :  {}", sl.maximumNumberOfStringPairs(v4));
  fmt::println("pairs :  {}", sl.maximumNumberOfStringPairs(v5));
  return EXIT_SUCCESS;
}
