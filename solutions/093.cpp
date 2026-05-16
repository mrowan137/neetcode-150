// problem: https://neetcode.io/problems/network-delay-time/question
// approach: Dijkstra
// complexity: O(E log V) time, O(V + E) space, E := num edges, V := num vertices
#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
 public:
  int networkDelayTime (std::vector<std::vector<int>>& times, int n, int k) {
    // construct graph
    std::unordered_map<int, std::vector<int>> g;
    std::map<std::pair<int, int>, int> delay;
    for (const auto& t : times) {
      int ui = t[0];
      int vi = t[1];
      int ti = t[2];
      g[ui].push_back(vi);  // uni-directional
      delay[{ui, vi}] = ti;
    }

    // find single-source shortest path from k using Dijkstra
    //
    // INVARIANT: when you pop node u with d = dist[u],
    // d is final; any future relaxation to u would have
    // to come from a node popped with distance >= d, but
    // adding a non-negative edge can't beat d
    std::priority_queue<std::pair<int, int>,
                   std::vector<std::pair<int, int>>,
                   std::greater<std::pair<int, int>>> pq;  // min heap
    pq.push({0, k});
    std::vector<int> dist(n + 1, INT_MAX);  // let dist[u] is the min distance,
    dist[k] = 0;                            // so far, to reach u from k
    std::unordered_set<int> seen;
    int res = 0;
    while (!pq.empty()) {
      // 1. process node w/ shortest distance to k
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      // 2. finalize u
      if (seen.count(u) != 0) continue;
      seen.insert(u);

      // 3. this is a valid shortest path -- update it
      res = std::max(res, d);  // longest shortest-path (last node to reach)

      // 4. explore neighbors
      for (int nbr : g[u]) {
        int new_dist = d + delay[{u, nbr}];  // distance via current node
        if (new_dist < dist[nbr]) {  // found a shorter path
          dist[nbr] = new_dist;  // update shortest dist to nbr
          pq.push({new_dist, nbr});  // add to queue for processing
        }
        // if new_dist >= dist[nbr], already have a better path
      }
    }

    return seen.size() == n ? res : -1;
  }
};
