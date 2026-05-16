// problem: https://neetcode.io/problems/jump-game/question
// approach: greedy; invariant: jump is remaining fuel before land on cell i;
//           each cell we either have the remaining fuel, or new fuel cell i,
//           and burn one for the next jump
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canJump (const std::vector<int>& nums) {
    int fuel = 0;  // invariant: fuel := remaining jumps before land on cell i
    for (int i = 0; i < nums.size(); ++i) {
      if (fuel < 0) return false;
      fuel = std::max(fuel, nums[i]) - 1;
    }
    return true;
  }
};
