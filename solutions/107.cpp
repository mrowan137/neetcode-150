// problem: https://neetcode.io/problems/maximum-product-subarray/question
// approach: DP; track max and min so far (up to i-1);
//           max product ending at i could be negative*min_so_far or positive*max_so_far
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProduct (const std::vector<int>& nums) {
    const int N = nums.size();
    int min_so_far = nums[0], max_so_far = nums[0], res = nums[0];
    for (int i = 1; i < N; ++i) {
      int tmp = min_so_far;
      min_so_far = std::min({nums[i], nums[i]*min_so_far, nums[i]*max_so_far});
      max_so_far = std::max({nums[i], nums[i]*tmp, nums[i]*max_so_far});
      res = std::max(res, max_so_far);
    }
    return res;
  }
};
