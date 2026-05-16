// problem: https://neetcode.io/problems/maximum-subarray/question
// approach: greedy; include only so long as cumulative sum is positive
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int maxSubArray (const std::vector<int>& nums) {
    int sum_so_far = 0;
    int max_sum = INT_MIN;
    for (int n : nums) {
      sum_so_far += n;
      max_sum = std::max(max_sum, sum_so_far);
      if (sum_so_far < 0) {  // reset if it can't help
        sum_so_far = 0;
      }
    }
    return max_sum;
  }
};
