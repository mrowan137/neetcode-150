// problem: https://neetcode.io/problems/n-queens/question
// approach: backtrack on allowed boards, representing row as bits
// complexity: O(exponential ~N) time, O(N) space, N := num rows
#include <cstdint>
#include <string>
#include <vector>

class Solution {
 private:
  std::vector<std::string> encode (int n, std::uint64_t board) {
    std::vector<std::string> res;
    for (int i = 0; i < n; ++i) {
      std::string row = "";
      for (int j = 0; j < n; ++j) {
        row += (board & 1) ? 'Q' : '.';
        board >>= 1;
      }
      res.push_back(row);
    }
    return res;
  }

  void backtrack (int n, int row,
                  std::uint64_t c, std::uint64_t l, std::uint64_t r,
                  std::uint64_t board, std::vector<std::vector<std::string>>& res) {
    if (row == n) {
      res.push_back(encode(n, board));
      return;
    }
    // invariant:
    //   row is the current row we construct
    //   c, l, r are blocked squares in current row
    //   board is the valid positions up to current row

    // construct allowed squared as negation of blocked squares
    std::uint64_t mask = (std::uint64_t(1) << n) - 1;
    std::uint64_t allowed = ~(c | l | r) & mask;
    while (allowed) {
      // queen can go in any allowed position, defining a new row
      std::uint64_t select = allowed & ~(allowed - 1);  // lsb
      backtrack(n,
                row + 1,
                c | select,
                (l | select) << 1,
                (r | select) >> 1,
                (board << n) | select,
                res);
      allowed ^= select;
    }
  }

 public:
  std::vector<std::vector<std::string>> solveNQueens (int n) {
    std::vector<std::vector<std::string>> res;
    backtrack(n,
              0,
              std::uint64_t(0),
              std::uint64_t(0),
              std::uint64_t(0),
              std::uint64_t(0),
              res);
    return res;
  }
};
