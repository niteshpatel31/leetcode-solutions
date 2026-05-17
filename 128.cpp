#include <cstdlib>
#include <fmt/base.h>
#include <iostream>
#include <unordered_set>
#include <vector>
class Solution {
public:
  const int longestConsecutive(std::vector<int> &nums) const {
    int max{1}, cur{1};
    std::unordered_set<int> seq;
    seq.reserve(nums.size());
    for (auto &e : nums) {
      seq.insert(e);
      for(auto &x : seq)
        if(seq.find)
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  Solution sol;
  std::vector<int> v1{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, v2{1, 0, 1, 2},
      v3{100, 4, 200, 1, 3, 2};
  fmt::println("longest sequence : {0}", sol.longestConsecutive(v1));
  // fmt::println("longest sequence : {0}", sol.longestConsecutive(v2));
  // fmt::println("longest sequence : {0}", sol.longestConsecutive(v3));
  return EXIT_SUCCESS;
}
