// problem: https://neetcode.io/problems/insert-new-interval/question
// approach: find insert; merge as needed; append remaining
// complexity: O(N) time, O(1) space, N := array size intervals
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> insert (const std::vector<std::vector<int>>& intervals, const std::vector<int>& newInterval) {
    const int N = intervals.size();
    std::vector<std::vector<int>> res;
    std::vector<int> ni = newInterval;

    // find insert location
    int i = 0;
    while (i < N && ni[0] > intervals[i][0]) {
      res.push_back(intervals[i++]);
    }

    // merge as needed
    if (0 < i && i <= N) {
      if (ni[0] <= intervals[i - 1][1]) {
        ni[0] = std::min(ni[0], intervals[i - 1][0]);
        ni[1] = std::max(ni[1], intervals[i - 1][1]);
        res.pop_back();
      }
    }
    while (i < N && intervals[i][0] <= ni[1]) {
      ni[1] = std::max(intervals[i++][1], ni[1]);
    }
    res.push_back(ni);

    // append remaining
    while (i < N) res.push_back(intervals[i++]);

    return res;
  }
};
