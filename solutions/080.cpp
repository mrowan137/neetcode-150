// problem: https://neetcode.io/problems/count-number-of-islands/question
// approach: DFS; flood-fill on any land cell, then mark explored
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <vector>

class Solution {
 private:
  void explore (int i, int j, std::vector<std::vector<char>>& grid) {
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    if (i > 0) explore(i - 1, j, grid);
    if (j > 0) explore(i, j - 1, grid);
    if (i < grid.size() - 1) explore(i + 1, j, grid);
    if (j < grid[0].size() - 1) explore(i, j + 1, grid);
    return;
  }

 public:
  int numIslands (std::vector<std::vector<char>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();

    int res = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == '1') {
          explore(i, j, grid);  // flood-fill grid
          res += 1;
        }
      }
    }
    return res;
  }
};
