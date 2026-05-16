// problem: https://neetcode.io/problems/count-connected-components/question
// approach: BFS search in unseen nodes, avoid tracking back to parent;
//           thus the BFS state can contain child,parent pairs
// complexity: O(V + E) time, O(V + E) space, V := num vertices, E := num edges
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int countComponents (int n, std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::vector<int>> graph;
    for (auto& ab : edges) {
      graph[ab[0]].push_back(ab[1]);
      graph[ab[1]].push_back(ab[0]);
    }

    // for each node in the graph, bfs if not seen
    int res = 0;
    std::unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
      if (seen.count(i) == 0) {
        std::queue<std::vector<int>> q({{i, -1}});
        while (!q.empty()) {
          int child = q.front()[0];
          int parent = q.front()[1];
          q.pop();

          if (seen.count(child) != 0) continue;
          seen.insert(child);

          for (int nbr : graph[child]) {
            if (nbr != parent) q.push({nbr, child});
          }
        }
        ++res;
      }
    }

    return res;
  }
};
