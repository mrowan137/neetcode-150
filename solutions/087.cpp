// problem: https://neetcode.io/problems/course-schedule/question
// approach: count in-degree for each node (number of prerequisites);
//           make a graph from node --> things depend on that node;
//           (because when we remove a node, we want to decrement deps);
//           while there are keys in in-degree map
//             collect pairs with count 0 (i.e. nodes to remove -- none means a cycle)
//             remove those from in-degree map, and for all deps, decrement their in-degree
// complexity: O(V^2 + E) time, O(V + E) space, V := num vertices, E := num edges
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool canFinish (int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, int> in_degree;
    std::unordered_map<int, std::vector<int>> graph;  // course, [things depend on course]
    for (int c = 0; c < numCourses; ++c) {
      in_degree[c] = 0;
    }
    for (auto& p : prerequisites) {
      in_degree[p[0]] += 1;
      graph[p[1]].push_back(p[0]);
    }

    while (!in_degree.empty()) {
      // find nodes to remove
      std::vector<int> remove;
      for (const auto& [course, deg] : in_degree) {
        if (deg == 0) remove.push_back(course);
      }

      // graph is not empty, but no nodes to remove --> cycle
      if (remove.empty()) return false;

      for (int c : remove) {
        in_degree.erase(c);
        for (int dep : graph[c]) {
          if (in_degree.count(dep)) {
            --in_degree[dep];
          }
        }
      }
    }

    return true;
  }
};
