// problem: https://neetcode.io/problems/minimum-interval-including-query/question
// approach: sort intervals by start and queries by value; use min-heap by length to track currently valid intervals
// complexity: O(N log N + M log M) time, O(M + N) space, N := array size intervals, M := array size queries
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> minInterval (std::vector<std::vector<int>>& intervals, const std::vector<int>& queries) {
    // sort intervals by increasing start
    std::sort(intervals.begin(), intervals.end(),
              [] (const auto& a, const auto& b) {
                return a[0] < b[0];
              });

    std::vector<std::pair<int, int>> qs;
    qs.reserve(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      qs.emplace_back(queries[i], i);
    }

    // sort queries by increasing value
    std::sort(qs.begin(), qs.end(),
              [] (const auto& a, const auto& b) {
                return a.first < b.first;
              });

    // min-heap by length to store currently valid intervals
    auto by_len = [] (const std::vector<int>& a, const std::vector<int>& b) {
      return (a[1] - a[0]) > (b[1] - b[0]);
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(by_len)> pq(by_len);

    std::vector<int> res(queries.size(), -1);
    int i = 0;  // index into intervals
    for (const auto& [q, j] : qs) {
      while (i < intervals.size() && intervals[i][0] <= q) {
        pq.push(intervals[i++]);
      }

      while (!pq.empty() && q > pq.top()[1]) {
        pq.pop();
      }

      res[j] = !pq.empty() ? 1 + pq.top()[1] - pq.top()[0] : -1;
    }

    return res;
  }
};
