// problem: https://neetcode.io/problems/last-stone-weight/question
// approach: max heap allows to take two largest and combine
// complexity: O(N log N) time, O(N) space, N := array size
#include <cstdlib>
#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight (const std::vector<int>& stones) {
    std::priority_queue<int> pq;
    for (int s : stones) pq.push(s);
    while (pq.size() > 1) {
      int x = pq.top(); pq.pop();
      int y = pq.top(); pq.pop();
      if (x != y) pq.push(std::abs(x - y));
    }

    return pq.empty() ? 0 : pq.top();
  }
};
