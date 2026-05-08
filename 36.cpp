#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  const bool isValidSudoku(std::vector<std::vector<char>> &board) const {
    std::unordered_set<char> row, col;
    std::vector<std::unordered_set<char>> square(9u);
    row.reserve(9u);
    col.reserve(9u);
    square.reserve(9u);
    size_t i{0u}, j{0u}, box{0u};
    for (j = 0u; j < board.size(); j++) {
      row.clear();
      col.clear();
      for (i = 0u; i < board[j].size(); i++) {
        box = (j / 3) * 3 + (i / 3);
        if (board[j][i] != '.') {
          if (row.count(board[j][i]) || square[box].count(board[j][i]))
            return false;

          if (board[j][i] != '.') {
            square[box].insert(board[j][i]);
            row.insert(board[j][i]);
          }
        }
        if (board[i][j] != '.') {
          if (col.count(board[i][j]))
            return false;
          if (board[i][j] != '.')
            col.insert(board[i][j]);
        }
      }
    }
    return true;
  }
};

int main(int argc, const char *argv[]) {
  std::vector<std::vector<char>> v1{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
      v2{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution sol;
  fmt::println("{}", sol.isValidSudoku(v1));
  fmt::println("{}", sol.isValidSudoku(v2));
  return EXIT_SUCCESS;
}
