// problem: https://neetcode.io/problems/longest-increasing-path-in-matrix/question
// approach v2: DFS + memo
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int search (int i, int j,
              const std::vector<std::vector<int>>& matrix, int M, int N,
              std::vector<std::vector<int>>& memo) {
    // exit
    if (memo[i][j] != -1) return memo[i][j];

    int longest = 1;
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (const auto& [di, dj] : dirs) {
      int ni = i + di, nj = j + dj;
      if (0 <= ni && ni < M && 0 <= nj && nj < N && matrix[i][j] < matrix[ni][nj]) {
        longest = std::max(longest, 1 + search(ni, nj, matrix, M, N, memo));
      }
    }
    return memo[i][j] = longest;
  }
  int longestIncreasingPath (const std::vector<std::vector<int>>& matrix) {
    const int M = matrix.size();
    const int N = matrix[0].size();

    int longest = INT_MIN;
    std::vector<std::vector<int>> memo(M, std::vector<int>(N, -1));  // longest path starting at i,j
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        longest = std::max(longest, search(i, j, matrix, M, N, memo));
      }
    }

    return longest;
  }
};

// approach v1: DFS + backtracking:
// complexity: O(4^(M*N)) time, O(M*N) space, M := rows, N := cols
class SlowSolution {
 public:
  void search (int i, int j,
               std::vector<std::vector<int>>& matrix, int M, int N,
               int curr_length, int& longest) {
    // exit
    if (matrix[i][j] == -1) return;

    longest = std::max(longest, curr_length);

    // mark
    int tmp = matrix[i][j];
    matrix[i][j] = -1;

    // explore
    if (1 <= i && tmp < matrix[i - 1][j] && matrix[i - 1][j] != -1)
      search(i - 1, j, matrix, M, N, curr_length + 1, longest);
    if (i < M - 1 && tmp < matrix[i + 1][j] && matrix[i + 1][j] != -1)
      search(i + 1, j, matrix, M, N, curr_length + 1, longest);
    if (1 <= j && tmp < matrix[i][j - 1] && matrix[i][j - 1] != -1)
      search(i, j - 1, matrix, M, N, curr_length + 1, longest);
    if (j < N - 1 && tmp < matrix[i][j + 1] && matrix[i][j + 1] != -1)
      search(i, j + 1, matrix, M, N, curr_length + 1, longest);

    // unmark
    matrix[i][j] = tmp;
  }
  int longestIncreasingPath (std::vector<std::vector<int>>& matrix) {
    const int M = matrix.size();
    const int N = matrix[0].size();

    int longest = INT_MIN;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        search(i, j, matrix, M, N, 1, longest);
      }
    }

    return longest;
  }
};
