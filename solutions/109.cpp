// problem: https://neetcode.io/problems/longest-increasing-subsequence/question
// approach: DP; iterate nums, and for each position before it search for any subsequence we can extend
// complexity: O(N^2) time, O(N) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int lengthOfLIS (const std::vector<int>& nums) {
    const int N = nums.size();
    // let dp[i] := length of longest increasing subseq ending at i
    std::vector<int> dp(N, 1);

    int res = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j]) dp[i] = std::max(dp[i], 1 + dp[j]);
      }
      res = std::max(res, dp[i]);
    }

    return res;
  }
};
