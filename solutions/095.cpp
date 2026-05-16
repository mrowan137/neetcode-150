// problem: https://neetcode.io/problems/min-cost-to-connect-points/question
// approach: Prim's algorithm -- start from a node;
//           consider all unvisited nodes and find their
//           cost to add to the tree from this node;
//           greedy add the closest one, and repeat
// complexity: O((log N)*N^2) time, O(N^2) space, N := num points
#include <cstdlib>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  int minCostConnectPoints (const std::vector<std::vector<int>>& points) {
    const int n = points.size();
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});  // cost, node idx
    int t = 0;
    while (!pq.empty()) {
      auto [c, idx] = pq.top(); pq.pop();
      if (visited[idx]) continue;
      visited[idx] = true;
      t += c;
      // add unvisited nbrs
      for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        int d = std::abs(points[i][0] - points[idx][0]) + std::abs(points[i][1] - points[idx][1]);
        pq.push({d, i});
      }
    }
    return t;
  }
};
