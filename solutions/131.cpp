// problem: https://neetcode.io/problems/merge-intervals/question
// approach: sort by first element, merge if overlaps, record non-overlaps
// complexity: O(N log N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge (std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> res;

    // sort by starts
    std::sort(intervals.begin(), intervals.end(),
              [] (const std::vector<int>& a, const std::vector<int>& b) {
                if (a[0] == b[0]) return a[1] < b[1];
                return a[0] < b[0];
              });

    // merge; outliers to result
    std::vector<int> curr = intervals[0];
    for (int i = 0; i < intervals.size() - 1; ++i) {
      std::vector<int> nxt = intervals[i + 1];
      if (curr[1] >= nxt[0]) {
        curr[1] = std::max(curr[1], nxt[1]);
      } else {
        res.push_back(curr);
        curr = intervals[i + 1];
      }
    }

    res.push_back(curr);  // final element
    return res;
  }
};
