#include <cinttypes>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <vector>

int main(int argc, const char *argv[]) {
  std::vector<int> vec = {1, 2};
  int price{0}, buy{0};
  for (int i = 1; i < vec.size(); i++) {
    buy = (vec[buy] < vec[i]) ? buy : i;
    int temp = vec[i] - vec[buy];
    fmt::println("price : {0}, j-i : {1} , buy : {2}", price, temp, buy);
    price = (price > temp) ? price : temp;
  }
  fmt::println("best time to sell : {}", price);
  return EXIT_SUCCESS;
}
