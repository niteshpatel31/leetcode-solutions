// link :
// https://neetcode.io/problems/string-encode-and-decode/question?list=neetcode150

#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
  std::string encode(std::vector<std::string> &strs) {
    std::string s;
    size_t size = strs.size();
    for (auto &e : strs)
      size += e.size();
    s.reserve(size);
    size = 0;
    for (auto &e : strs) {
      s += e;
      s += '\f';
    }
    return s;
  }

  std::vector<std::string> decode(std::string &s) {
    std::vector<std::string> list;
    list.reserve(s.size());
    std::string str;
    str.reserve(s.size());
    for (auto &c : s) {
      if (c == '\f') {
        list.push_back(str);
        str = "";
      } else
        str.push_back(c);
    }
    return list;
  }
};

int main(const int argc, const char *argv[]) {
  std::vector<std::string> v1{"Hello", "World"};
  Solution sl;
  std::string str = sl.encode(v1);
  std::vector<std::string> list = sl.decode(str);
  for (auto &e : list)
    std::cout << e << std::endl;
  return EXIT_SUCCESS;
}
