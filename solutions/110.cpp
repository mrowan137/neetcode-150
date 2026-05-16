
// problem: https://neetcode.io/problems/partition-equal-subset-sum/question
// approach: DP; iterate backward to enforce single-use
// complexity: O(N*M) time, O(M) space, N := array size, M := target
#include <numeric>
#include <vector>

class Solution {
 public:
  bool canPartition (const std::vector<int>& nums) {
    // goal: construct set sums to sum(nums)/2, no replacement
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    if (s%2 == 1) return false;
    int target = s/2;
    // let dp[i] := sum i reachable
    std::vector<bool> dp(target + 1, false);  // O(target) space
    dp[0] = true;  // base case: sum of 0 achievable w/ 0 coins

    // O(len(nums)*target) time
    for (int n : nums) {
      for (int i = target; i >= n; --i) {
        // counting upward could update dp and use it in the same pass,
        // effectively re-using n; count down to enforce single-use
        if (dp[i - n]) dp[i] = true;
      }
      if (dp[target]) return true;
    }

    return dp[target];
  }
};
