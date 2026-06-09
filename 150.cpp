#include <cstdlib>
#include <fmt/format.h>
#include <vector>

class Solution {
public:
  const int evalRPN(const std::vector<std::string> &tokens) const noexcept {
    std::vector<int> num;
    num.reserve(tokens.size() / 2 + 1);
    int a{}, b{};

    auto isOperator = [](const std::string &s) {
      return s.size() == 1 &&
             (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
    };

    for (const std::string &s : tokens) {
      if (!isOperator(s))
        num.push_back(std::atoi(s.c_str()));
      else {
        a = num[num.size() - 1];
        num.pop_back();
        b = num[num.size() - 1];
        num.pop_back();
        switch (s[0]) {
        case '+':
          b = b + a;
          break;
        case '-':
          b = b - a;
          break;
        case '/':
          b = b / a;
          break;
        case '*':
          b = b * a;
          break;
        }
        num.emplace_back(b);
        // fmt::println(" a : {1}, b: {0}, b : {2},", b, a, ans);
      }
    }
    return num[num.size() - 1];
  }
};

int main(const int argc, const char *argv[]) {
  Solution sl;
  const std::vector<std::string> v1{"2", "1", "+", "3", "*", "4", "-"},
      v2{"4", "13", "5", "/", "+"},
      v3{
          "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+",
      },
      v4{"1", "2", "+", "3", "*", "4", "-"};
  fmt::println("b : {}", sl.evalRPN(v1));
  fmt::println("b : {}", sl.evalRPN(v2));
  fmt::println("b : {}", sl.evalRPN(v3));
  fmt::println("b : {}", sl.evalRPN(v4));
  return EXIT_SUCCESS;
}
