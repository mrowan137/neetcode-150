// problem: https://neetcode.io/problems/house-robber/question
// approach: DP
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob (const std::vector<int>& nums) {
    const int N = nums.size();
    if (N == 0) return 0;
    if (N == 1) return nums[0];
    int x = nums[0];
    int y = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < N; ++i) {
      int tmp = y;
      y = std::max(x + nums[i], y);
      x = tmp;
    }
    return y;
  }
};
