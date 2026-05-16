// problem: https://neetcode.io/problems/reconstruct-flight-path/question
// approach: Hierholzer algorithm; DFS lexicographic order as far as you can go then backtrace
// complexity: O(E log E) time, O(E) space, E := num edges
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  void dfs (const std::string& s,
            std::unordered_map<std::string, std::multiset<std::string>>& g,
            std::vector<std::string>& p) {
    while (!g[s].empty()) {
      std::string nxt = *g[s].begin();
      g[s].erase(g[s].begin());
      dfs(nxt, g, p);
    }
    p.push_back(s);
  }
  std::vector<std::string> findItinerary (const std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string, std::multiset<std::string>> g;
    for (const auto& t : tickets) g[t[0]].insert(t[1]);
    std::vector<std::string> p;
    dfs("JFK", g, p); std::reverse(p.begin(), p.end());
    return p;
  }
};
