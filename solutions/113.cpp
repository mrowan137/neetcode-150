// problem: https://neetcode.io/problems/buy-and-sell-crypto-with-cooldown/question
// approach: DP; case 1: pass; case 2: transact
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProfit (const std::vector<int>& prices) {
    const int N = prices.size();
    if (N < 2) return 0;

    // let dp[i] := max profit up to day i
    // dp[i] = max( dp[i-1],
    //              max_{j<i}(prices[i] - prices[j] + dp[j-2]) )
    // max_{j<i}( prices[i] - prices[j] + dp[j-2] )
    //   = prices[i] + max_{j<i}( dp[j-2] - prices[j] )
    //  := prices[i] + best_i
    int prev2 = 0, prev1 = 0, curr = 0;  // dp[i-2], dp[i-1], dp[i]
    int best = -1*prices[0];
    for (int i = 1; i < N; ++i) {
      curr = std::max(prev1,              // case 1: do nothing
                      prices[i] + best);  // case 2: transact; (prices[i] - prices[jbest]) + dp[jbest-2]
      int maybe_buy = prev2 - prices[i];
      best = std::max(best, maybe_buy);
      prev2 = prev1;
      prev1 = curr;
    }
    return curr;
  }
};
