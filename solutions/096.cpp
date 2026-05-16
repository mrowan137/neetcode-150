// problem: https://neetcode.io/problems/swim-in-rising-water/question
// approach: Dijkstra: explore the GLOBALLY cheapest unexplored option, next (priority queue)
// complexity: O((log N)*N^2) time, O(N^2) space, N := num rows or cols in grid
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

class Solution {
 public:
  int swimInWater (std::vector<std::vector<int>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});  // t,i,j
    std::vector<std::vector<bool>> seen(m, std::vector<bool>(n, false));
    while (!pq.empty()) {
      int t = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
      pq.pop();

      if (seen[i][j]) continue;
      seen[i][j] = true;

      if ((i == m - 1) && (j == n - 1)) return t;

      for (const auto& d : dirs) {
        int ni = i + d[0], nj = j + d[1];
        if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
        pq.push({std::max(grid[ni][nj], t), ni, nj});
      }
    }

    return -1;
  }
};
