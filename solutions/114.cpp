// problem: https://neetcode.io/problems/coin-change-ii/question
// approach: DP; loop coins*amount but dp[i] := ways to reach i,
//           using coins up to c_j (with c as outer loop)
// complexity: O(M*N) time, O(M) space, N := array size, M := amount
#include <vector>

class Solution {
 public:
  int change (int amount, const std::vector<int>& coins) {
    // let dp[i] := number of ways to reach i;
    // enforcing outer loop on coins, then dp[i]
    // further means number of eays to reach i, using
    // coins up to c_j; this ordering in the coins means
    // we avoid counting permutation sums as equivalent
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // 1 way to reach amount 0 using 0 coins
    for (int c : coins) {
      for (int a = c; a <= amount; ++a) {
        // ascending loop allows reuse of c
        // (dp[a] is updated on-the-fly)
        dp[a] += dp[a - c];
      }
    }

    return dp[amount];
  }
};
