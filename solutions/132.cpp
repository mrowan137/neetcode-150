// problem: https://neetcode.io/problems/non-overlapping-intervals/question
// approach: greedy; sort by start; hang on to smallest end for currently overlapping intervals,
//           and increment as long as overlap to count drops;
//           when find a gap, reset endpoint and repeat
// complexity: O(N log N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int eraseOverlapIntervals (std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [] (const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
              });

    int res = 0;  // minimum number of intervals to drop
    int end = intervals[0][1];  // end of current non-overlap section
    for (int i = 0; i < intervals.size() - 1; ++i) {
      const std::vector<int>& nxt = intervals[i + 1];
      if (nxt[0] < end) {
        // when are we force to drop an interval?
        // when end of current best overlaps the next;
        // greedily take any better endpoint
        // (i.e. drop the worse interval)
        ++res;
        end = std::min(end, nxt[1]);
      } else {
        // if we made it here, we found a gap;
        // reset end to repeat the process
        end = nxt[1];
      }
    }

    return res;
  }
};
