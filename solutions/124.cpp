// problem: https://neetcode.io/problems/jump-game-ii/question
// approach v2: greedy; scan windows for best result; at end of a window,
//              we know best result and can make a jump, and set next window
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int jump (const std::vector<int>& nums) {
    // jump when you must (at end of window), and set the
    // new window; problem guarantees end is reachable.
    // why we need two variables, furthest and end-- why
    // is one not enough?
    //   end tracks the scanning range;
    //   furthest tracks furthest reachable in the scan;
    // we need to scan the full range before commit to
    // a given furthest, i.e. a new end
    int jumps = 0, furthest = 0, end = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      furthest = std::max(furthest, i + nums[i]);
      if (i == end) {
        ++jumps;
        end = furthest;
      }
    }
    return jumps;
  }
};

// approach v1: greedy; explore cells in-range and jump
// complexity: O(N^2) time, O(1) space, N := array size
class SlowSolution {
 public:
  int jump (const std::vector<int>& nums) {
    // for each cell in range, consider which will
    // take us the furthest, and jump to there
    int i = 0, jumps = 0;
    while (i != nums.size() - 1) {
      int furthest = INT_MIN, prev = INT_MIN, jmax = i;
      const int lim = std::min(i + nums[i], static_cast<int>(nums.size() - 1));
      for (int j = i + 1; j <= lim; ++j) {
        furthest = std::max(furthest, j + nums[j]);
        if (j + nums[j] >= prev) {
          prev = furthest;
          jmax = j;
        }
      }
      i = i + nums[i] >= nums.size() - 1? nums.size() - 1 : jmax;
      ++jumps;
    }
    return jumps;
  }
};
