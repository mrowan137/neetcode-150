// problem: https://neetcode.io/problems/cheapest-flight-path/question
// approach: BFS with multidimensional tracking on {airport, remaining stops} to track best price so far
// complexity: O(M*K) time, O(M + N*K) space, M := num flights, K := num stops, N := num cities
#include <algorithm>
#include <climits>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  int findCheapestPrice (int n, const std::vector<std::vector<int>>& flights, int src, int dst, int k) {
    // construct graph[src] := {dst, price}
    std::unordered_map<int, std::vector<std::pair<int, int>>> g;
    for (const auto& f : flights) {
      g[f[0]].push_back(std::pair<int, int>({f[1], f[2]}));
    }

    // curr airport, cumulative price, remaining flights (edges);
    // note k is max number of intermediate airports (w/o src, dst),
    // so initialize w/ k+1 allowed remaining flights
    std::queue<std::tuple<int, int, int>> q;  // src,price,remaining
    q.push({src, 0, k + 1});
    std::vector<std::vector<int>> seen(n, std::vector<int>(k + 2, INT_MAX));  // track cheapest cumulative price
    while (!q.empty()) {                                                      // at airport given remaining
      auto [airport, price, remaining] = q.front();                           // flights, [0,k+1] inclusive
      q.pop();
      if (remaining < 0 || seen[airport][remaining] < price) continue;
      if (airport == dst) {
        continue;
      }

      for (auto nbr : g[airport]) {
        if (remaining == 0) continue;
        if (price + nbr.second < seen[nbr.first][remaining - 1]) {
          seen[nbr.first][remaining - 1] = price + nbr.second;
          q.push({nbr.first, price + nbr.second, remaining - 1});
        }
      }
    }

    int cheapest = *std::min_element(seen[dst].begin(), seen[dst].end());
    return cheapest != INT_MAX ? cheapest : -1;
  }
};
