// problem: https://neetcode.io/problems/coin-change/question
// approach: DP; iterate coins then amount, caching best result for each sub-amount
// complexity: O(M*N) time, O(M) space, N := array size, M := amount
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int coinChange (const std::vector<int>& coins, int amount) {
    // dp[i] := min coins to reach amount i
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int c : coins) {
      for (int i = c; i <= amount; ++i) {
        if (dp[i - c] != INT_MAX) dp[i] = std::min(dp[i], dp[i - c] + 1);
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
