// problem: https://neetcode.io/problems/course-schedule-ii/question
// approach: same as Course Schedule I (087), just return valid course order
// complexity: O(V^2 + E) time, O(V + E) space, V := num vertices, E := num edges
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> findOrder (int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> res;
    std::unordered_map<int, int> in_degree;
    std::unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < numCourses; ++i) in_degree[i] = 0;
    for (auto& p : prerequisites) {
      ++in_degree[p[0]];
      graph[p[1]].push_back(p[0]);
    }

    while (!in_degree.empty()) {
      std::vector<int> remove;
      for (auto& p : in_degree) {
        if (p.second == 0) {
          res.push_back(p.first);
          remove.push_back(p.first);
        }
      }

      if (remove.empty()) return {};

      for (int c : remove) {
        in_degree.erase(c);
        for (int d : graph[c]) --in_degree[d];
      }
    }
    return res;
  }
};
