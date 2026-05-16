// problem: https://neetcode.io/problems/max-area-of-island/question
// approach: DFS; flood-fill with recursive sum
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <algorithm>
#include <vector>

class Solution {
 private:
  int explore (int i, int j, std::vector<std::vector<int>>& grid) {
    if (grid[i][j] == 0) return 0;

    grid[i][j] = 0;  // don't count this anymore
    int res = ( 1 + (i > 0 ? explore(i - 1, j, grid) : 0)
                + (j > 0 ? explore(i, j - 1, grid) : 0)
                + (i < grid.size() - 1 ? explore(i + 1, j, grid) : 0)
                + (j < grid[0].size() - 1 ? explore(i, j + 1, grid) : 0) );
    return res;
  }

 public:
  int maxAreaOfIsland (std::vector<std::vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();
    int res = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == 1) {
          res = std::max(res, explore(i, j, grid));
        }
      }
    }
    return res;
  }
};
