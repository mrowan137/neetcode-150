// problem: https://neetcode.io/problems/islands-and-treasure/question
// approach: BFS from each land cell to nearest treasure
// complexity: O((M*N)^2) time, O(M*N) space, M := rows, N := cols
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <vector>

class Solution {
 enum class ISL {
   TREASURE = 0,
   WATER = -1,
   LAND = INT_MAX
 };
 private:
  void bfs (int i0, int j0, std::vector<std::vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();

    // bfs land positions together
    std::deque<std::vector<int>> dq({{i0, j0, 0}});  // i0,j0,ic,jc,steps
    std::set<std::pair<int, int>> s;
    while (!dq.empty()) {
      int ic = dq.front()[0];
      int jc = dq.front()[1];
      int steps = dq.front()[2];
      dq.pop_front();
      if (s.find({ic, jc}) != s.end()) continue;
      s.insert({ic, jc});
      if (static_cast<ISL>(grid[ic][jc]) == ISL::TREASURE) {
        grid[i0][j0] = steps;
        return;
      }
      int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      for (const auto& d : dirs) {
        int ni = ic + d[0], nj = jc + d[1];
        // skip water or OOB -- explore land or treasure
        if (ni < 0 || nj < 0 || ni >= M || nj >= N
            || static_cast<ISL>(grid[ni][nj]) == ISL::WATER) continue;
        dq.push_back({ni, nj, steps + 1});
      }
    }
  }

 public:
  void islandsAndTreasure (std::vector<std::vector<int>>& grid) {
    // look for nearest treasure --> BFS
    const int M = grid.size();
    const int N = grid[0].size();

    // initial land positions
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (static_cast<ISL>(grid[i][j]) != ISL::WATER) {
          bfs(i, j, grid);
        }
      }
    }
  }
};
