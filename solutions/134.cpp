// problem: https://neetcode.io/problems/meeting-schedule-ii/question
// approach: use a min-heap to track earliest available time;
//           if overlap earliest time, we need a new room and insert this new earliest time to the min-heap
//           if there's a valid earliest time w/ no overlap, add the new earliest time and drop the previous one
// complexity: O(N log N) time, O(N) space, N := array size
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

struct Interval {
  int start = 0;
  int end = 0;

  Interval () = default;
  Interval (int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  int minMeetingRooms (std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [] (const Interval& a, const Interval& b) {
                return a.start < b.start;
              });
    // min heap to track the smallest end
    // from among allocated intervals
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // check the earliest available slot; if non-overlapping,
    // interval is allocated for that room; else needs a new room
    for (const auto& meet : intervals) {
      if (!pq.empty() && pq.top() <= meet.start) pq.pop();
      pq.push(meet.end);
    }

    return pq.size();
  }
};
