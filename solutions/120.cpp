// problem: https://neetcode.io/problems/burst-balloons/question
// approach: 2D DP; let dp[l][r] := max profit after all balloons on [l+1,r-1] are popped;
//           build solution in increasing subarrays [l,r] where r = l+len, len=2,3,..;
//           for each subarray, try every balloon in [l+1,r-1] as last one popped
// complexity: O(N^3) time, O(N^2) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCoins (const std::vector<int>& nums) {
    const int N = nums.size();

    std::vector<std::vector<int>> dp(N + 2, std::vector<int>(N + 2, 0));
    std::vector<int> b(N + 2, 1);  // pad nums with [1] balloons
    for (int i = 0; i < N; ++i) b[i + 1] = nums[i];

    for (int len = 2; len < N + 2; ++len) {
      for (int l = 0; l + len < N + 2; ++l) {
        int r = l + len;
        for (int i = l + 1; i < r; ++i) {
          dp[l][r] = std::max(dp[l][r], dp[l][i]
                              + b[l]*b[i]*b[r]
                              + dp[i][r]);
        }
      }
    }

    return dp[0][N + 1];
  }
};
