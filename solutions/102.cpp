// problem: https://neetcode.io/problems/house-robber-ii/question
// approach: DP
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob (const std::vector<int>& nums) {
    const int N = nums.size();
    if (N == 1) return nums[0];
    if (N == 2) return std::max(nums[0], nums[1]);

    // rob first house
    int res = 0;
    int x = 0, y = nums[0], z = 0;
    for (int i = 1; i < N - 1; ++i) {
      z = std::max(y, x + nums[i]);
      x = y;
      y = z;
    }
    res = std::max(res, z);

    // don't rob first house
    x = 0, y = 0, z = 0;
    for (int i = 1; i < N; ++i) {
      z = std::max(y, x + nums[i]);
      x = y;
      y = z;
    }
    res = std::max(res, z);

    return res;
  }
};
