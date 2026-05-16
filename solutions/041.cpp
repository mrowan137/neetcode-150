// problem: https://neetcode.io/problems/find-duplicate-integer/question
// approach: Floyd's cycle detection
// complexity: O(N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  int findDuplicate (const std::vector<int>& nums) {
    int s = 0, f = 0;
    bool first = true;
    while (first || s != f) {
      f = nums[nums[f]];
      s = nums[s];
      first = false;
    }

    s = 0;
    while (s != f) {
      f = nums[f];
      s = nums[s];
    }

    return s;
  }
};
