// problem: https://neetcode.io/problems/meeting-schedule/question
// approach: sort by start, check for overlaps
// complexity: O(N log N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

struct Interval {
  int start = 0;
  int end = 0;

  Interval () = default;
  Interval (int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  bool canAttendMeetings (std::vector<Interval>& intervals) {
    if (intervals.empty()) return true;

    // sort by start, check for overlap
    std::sort(intervals.begin(), intervals.end(),
              [] (const Interval& a, const Interval& b) {
                if (a.start == b.start) return a.end < b.end;
                return a.start < b.start;
              });
    for (int i = 0; i < intervals.size() - 1; ++i) {
      const Interval& curr = intervals[i];
      const Interval& nxt = intervals[i + 1];
      if (curr.end > nxt.start) return false;
    }
    return true;
  }
};
