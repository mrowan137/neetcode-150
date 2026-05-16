// problem: https://neetcode.io/problems/rotate-matrix/question
// approach: 90 deg rotation == transpose and reverse
// complexity: O(M*N) time, O(1) space, M := rows, N := cols
#include <algorithm>
#include <vector>

class Solution {
 public:
  void rotate (std::vector<std::vector<int>>& matrix) {
    // 90 deg rotation == transpose & reverse
    const int N = matrix.size();
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }

    for (auto& row : matrix) {
      std::reverse(row.begin(), row.end());
    }
  }
};
