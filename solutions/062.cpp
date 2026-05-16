// problem: https://neetcode.io/problems/k-closest-points-to-origin/question
// approach: max heap, keeping it small when possible for cheaper insertion
// complexity: O(N log K) time, O(K) space, N := array size, K := heap size
#include <queue>
#include <vector>

class Solution {
  using point = std::vector<int>;
  struct comp {
    bool operator() (const point& p1, const point& p2) const {
      int d1 = p1[0]*p1[0] + p1[1]*p1[1];
      int d2 = p2[0]*p2[0] + p2[1]*p2[1];
      return  d1 < d2;
    }
  };

 public:
  std::vector<std::vector<int>> kClosest (const std::vector<std::vector<int>>& points, int k) {
    // we want k smallest, so use a maxheap and remove those bigger
    std::priority_queue<point, std::vector<point>, comp> pq;

    for (const point& p : points) {
      pq.push(p);
      if (pq.size() > k) pq.pop();
    }

    std::vector<point> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }

    return res;
  }
};
