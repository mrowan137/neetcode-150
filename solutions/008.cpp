// problem: https://neetcode.io/problems/valid-sudoku/question
// approach v2: one pass and maintain sets for rows,cols,boxes
// complexity: O(N) time, O(1) space, N := number of cells
#include <cstddef>
#include <set>
#include <vector>

class Solution {
 public:
  bool isValidSudoku (const std::vector<std::vector<char>>& board) {
    // 9 rows, 9 cols, 9 boxes
    // each can have no repeat digit
    std::vector<std::set<char>> rows(9);
    std::vector<std::set<char>> cols(9);
    std::vector<std::set<char>> boxes(9);

    // one-pass iterate and put in the right set
    for (std::size_t i = 0; i < 9; ++i) {
      for (std::size_t j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.') continue;

        if (rows[i].count(c) != 0) return false;
        rows[i].insert(c);

        if (cols[j].count(c) != 0) return false;
        cols[j].insert(c);

        std::size_t k = (i/3)*3 + (j/3);
        if (boxes[k].count(c) != 0) return false;
        boxes[k].insert(c);
      }
    }
    return true;
  }
};

// approach v1: three passes to check rows,cols,boxes
// complexity: O(3*N) = O(N) time, O(1) space, N := number of cells
class AltSolution {
 public:
  bool valid_rows (const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
      int digits[9] = {};
      for (char c : row) {
        if (c != '.') ++digits[c - '1'];
      }
      for (int n : digits) {
        if (n > 1) return false;
      }
    }
    return true;
  }

  bool valid_cols (const std::vector<std::vector<char>>& board) {
    for (int c = 0; c < 9; ++c) {
      int digits[9] = {};
      for (int r = 0; r < 9; ++r) {
        if (board[r][c] != '.') ++digits[board[r][c] - '1'];
      }
      for (int n : digits) {
        if (n > 1) return false;
      }
    }
    return true;
  }

  bool valid_boxes (const std::vector<std::vector<char>>& board) {
    for (int r = 0; r < 9; r += 3) {
      for (int c = 0; c < 9; c += 3) {
        // take a starting corner for the box
        int digits[9] = {};
        for (int i = r; i < r + 3; ++i) {
          for (int j = c; j < c + 3; ++j) {
            if (board[i][j] != '.') ++digits[board[i][j] - '1'];
          }
        }
        for (int n : digits) {
          if (n > 1) return false;
        }
      }
    }
    return true;
  }

  bool isValidSudoku (const std::vector<std::vector<char>>& board) {
    if (!valid_rows(board)) return false;
    if (!valid_cols(board)) return false;
    if (!valid_boxes(board)) return false;
    return true;
  }
};
