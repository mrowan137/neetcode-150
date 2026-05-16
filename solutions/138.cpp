// problem: https://neetcode.io/problems/set-zeroes-in-matrix/question
// approach: use zeroth row & col to track target rows & cols from inner matrix;
//           use bools to track whether zeroth row & col get zeroed
// complexity: O(M*N) time, O(1) space, M := rows, N := cols
#include <cstddef>
#include <vector>

class Solution {
 public:
  void setZeroes (std::vector<std::vector<int>>& matrix) {
    const std::size_t M = matrix.size();
    const std::size_t N = matrix[0].size();

    // store for later whether needs to zero 0th row & col
    bool zero_first_col = false;
    for (int i = 0; i < M; ++i) {
      if (matrix[i][0] == 0) {
        zero_first_col = true;
        break;
      }
    }
    bool zero_first_row = false;
    for (int j = 0; j < N; ++j) {
      if (matrix[0][j] == 0) {
        zero_first_row = true;
        break;
      }
    }

    // use 0th row and column to track targets
    for (int i = 1; i < M; ++i) {
      for (int j = 1; j < N; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // zero out target rows & cols
    for (int i = 1; i < M; ++i) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < N; ++j) matrix[i][j] = 0;
      }
    }
    for (int j = 1; j < N; ++j) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < M; ++i) matrix[i][j] = 0;
      }
    }

    // handle first row & col
    if (zero_first_col) {
      for (int i = 0; i < M; ++i) matrix[i][0] = 0;
    }
    if (zero_first_row) {
      for (int j = 0; j < N; ++j) matrix[0][j] = 0;
    }
  }
};
