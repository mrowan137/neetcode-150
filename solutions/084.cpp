// problem: https://neetcode.io/problems/rotting-fruit/question
// approach: BFS; rot one fruit per step, simultaneously
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <deque>
#include <vector>

class Solution {
 enum class OJ {
   NONE = 0,
   FRESH = 1,
   ROT = 2
 };

 public:
  int orangesRotting (std::vector<std::vector<int>>& grid) {
    const int M = grid.size();
    const int N = grid[0].size();

    std::deque<std::vector<int>> dq;
    int fresh = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        // we start from rotting positions
        if (static_cast<OJ>(grid[i][j]) == OJ::ROT) dq.push_back({i, j, 0});
        else if (static_cast<OJ>(grid[i][j]) == OJ::FRESH) ++fresh;
      }
    }

    int time = 0;
    while (!dq.empty()) {
      int i = dq.front()[0];
      int j = dq.front()[1];
      int elapsed = dq.front()[2];
      dq.pop_front();

      time = elapsed;

      // skip empty or rotten
      int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      for (auto& d : dirs) {
        int ni = i + d[0], nj = j + d[1];
        if (ni < 0 || nj < 0 || ni >= M || nj >= N
            || static_cast<OJ>(grid[ni][nj]) != OJ::FRESH) continue;
        --fresh;  // infect a fresh, decrement
        grid[ni][nj] = static_cast<int>(OJ::ROT);  // rot the neighbor
        dq.push_back({ni, nj, elapsed + 1});
      }
    }

    return fresh == 0 ? time : -1;
  }
};
