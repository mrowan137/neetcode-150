// problem: https://neetcode.io/problems/pacific-atlantic-water-flow/question
// approach v2: BFS; search edge for land connect to pacific, atlantic and take intersection
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
 private:
  void bfs (const std::vector<std::vector<int>>& heights, const int M, const int N,
           std::queue<std::vector<int>>& q, std::vector<std::vector<bool>>& r) {
    std::unordered_set<int> seen;
    while (!q.empty()) {
      int i = q.front()[0];
      int j = q.front()[1];
      q.pop();
      if (seen.count(i*N + j) != 0) continue;
      seen.insert(i*N + j);
      r[i][j] = true;
      int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      for (auto& d : dirs) {
        int ni = i + d[0];
        int nj = j + d[1];
        if (0 <= ni && ni < M
            && 0 <= nj && nj < N
            && heights[i][j] <= heights[ni][nj]) q.push({ni, nj});
      }
    }
  }

 public:
  std::vector<std::vector<int>> pacificAtlantic (std::vector<std::vector<int>>& heights) {
    const int M = heights.size();
    const int N = heights[0].size();
    std::queue<std::vector<int>> p;
    std::queue<std::vector<int>> a;
    int i = 0;
    for (int j = 0; j < N; ++j) p.push({i, j});
    int j = 0;
    for (int i = 1; i < M; ++i) p.push({i, j});
    i = M - 1;
    for (int j = 0; j < N; ++j) a.push({i, j});
    j = N - 1;
    for (int i = 0; i < M - 1; ++i) a.push({i, j});

    std::vector<std::vector<bool>> ar(M, std::vector<bool>(N, false));
    std::vector<std::vector<bool>> pr(M, std::vector<bool>(N, false));
    bfs(heights, M, N, a, ar);
    bfs(heights, M, N, p, pr);

    std::vector<std::vector<int>> res;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (ar[i][j] && pr[i][j]) res.push_back({i, j});
      }
    }

    return res;
  }
};

// approach v1: DFS; search edge for land connect to pacific, atlantic and take intersection
// complexity: O(3^(M*N)) time, O(M*N) space, M := rows, N := cols
class SlowSolution {
  enum class OCEAN {
    ATLANTIC = 0,
    PACIFIC = 1
  };

 private:
  bool dfs (int i, int j,
            std::vector<std::vector<int>>& heights,
            OCEAN which_one) {
    // early exit
    if (heights[i][j] == -1) return false;

    const int M = heights.size();
    const int N = heights[0].size();
    if (which_one == OCEAN::ATLANTIC
        && (i == M - 1 || j == N - 1)) {
      return true;
    } else if (which_one == OCEAN::PACIFIC
               && (i == 0 || j == 0)) {
      return true;
    }
    int curr = heights[i][j];
    heights[i][j] = -1;  // mark seen
    bool ret = false;
    if (i > 0 && curr >= heights[i - 1][j]) {
      ret = ret||dfs(i - 1, j, heights, which_one);
    }
    if (j > 0 && curr >= heights[i][j - 1]) {
      ret = ret|| dfs(i, j - 1, heights, which_one);
    }
    if (i < M - 1 && curr >= heights[i + 1][j]) {
      ret = ret|| dfs(i + 1, j, heights, which_one);
    }
    if (j < N - 1 && curr >= heights[i][j + 1]) {
      ret = ret|| dfs(i, j + 1, heights, which_one);
    }
    heights[i][j] = curr;  // unmark
    return ret;
  }

 public:
  std::vector<std::vector<int>> pacificAtlantic (std::vector<std::vector<int>>& heights) {
    // dfs each cell for a path to pacific AND atlantic
    std::vector<std::vector<int>> res;
    const int M = heights.size();
    const int N = heights[0].size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        bool a = dfs(i, j, heights, OCEAN::ATLANTIC);
        bool p = dfs(i, j, heights, OCEAN::PACIFIC);
        if (a && p) res.push_back({i, j});
      }
    }
    return res;
  }
};
