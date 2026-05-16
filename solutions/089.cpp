// problem: https://neetcode.io/problems/valid-tree/question
// approach: BFS to see if you can hit all the nodes;
//           track current & parent, to avoid backtracking to the parent;
//           return false on cycle detection
// complexity: O(V + E) time, O(V + E) space, V := num vertices, E := num edges
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool validTree (int n, std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::vector<int>> graph;
    for (auto& ab : edges) {
      graph[ab[1]].push_back(ab[0]);
      graph[ab[0]].push_back(ab[1]);
    }

    std::set<int> seen;
    std::queue<std::vector<int>> q({{0, -1}});  // node,parent
    while (!q.empty()) {
      int curr = q.front()[0];
      int parent = q.front()[1];
      q.pop();

      if (seen.count(curr) != 0) return false;
      seen.insert(curr);
      for (int nbr : graph[curr]) {
        if (parent != nbr) q.push({nbr, curr});
      }
    }

    return seen.size() == n;
  }
};
