// problem: https://neetcode.io/problems/redundant-connection/question
// approach v2: union find; connect the boss nodes if distinct otherwise already connected
// complexity: O(V*E) time, O(V) space, V := num vertices, E := num edges
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

class UnionFind {
 private:
  std::vector<int> boss;

 public:
  UnionFind (int n) : boss(n) {
    for (int i = 0; i < n; ++i) boss[i] = i;
  }

  int find (int i) {
    if (boss[i] == i) return i;
    return find(boss[i]);
  }

  bool unite (int friend1, int friend2) {
    int boss1 = find(friend1);
    int boss2 = find(friend2);
    if (boss1 == boss2) return false;  // same group already
    boss[boss1] = boss2;
    return true;
  }
};

class Solution {
 public:
  std::vector<int> findRedundantConnection (const std::vector<std::vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);
    for (auto& ab : edges) {
      if (!uf.unite(ab[0], ab[1])) return ab;
    }
    return {};  // don't get here for happy inputs
  }
};

// approach v1: brute force; construct graph excluding edge, check if connected
// complexity: O(E^2 + E*V) time, O(V + E) space, E := num edges, V := num vertices
class SlowSolution {
 private:
  bool connected (const std::set<int>& nodes, const std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::vector<int>> graph;
    for (auto& ab : edges) {
      graph[ab[0]].push_back(ab[1]);
      graph[ab[1]].push_back(ab[0]);
    }

    std::queue<std::vector<int>> q({{*nodes.begin(), -1}});
    std::set<int> seen;
    while (!q.empty()) {
      int n = q.front()[0];
      int parent = q.front()[1];
      q.pop();

      if (seen.count(n) != 0) continue;
      seen.insert(n);

      for (int nbr : graph[n]) {
        if (nbr != parent) q.push({nbr, n});
      }
    }

    return seen.size() == nodes.size();
  }

 public:
  std::vector<int> findRedundantConnection (const std::vector<std::vector<int>>& edges) {
    std::vector<int> ret = {};
    for (auto& ab : edges) {
      // construct graph excluding this edge
      std::vector<std::vector<int>> copy;
      std::set<int> nodes;
      for (auto& xy : edges) {
        if (xy != ab) copy.push_back(xy);
        nodes.insert(xy[0]);
        nodes.insert(xy[1]);
      }

      // check if it's fully connected
      if (connected(nodes, copy)) ret = ab;
    }

    return ret;
  }
};
