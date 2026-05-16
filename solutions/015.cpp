// problem: https://neetcode.io/problems/buy-and-sell-crypto/question
// approach: use clairvoyance to buy low, sell high
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int maxProfit (const std::vector<int>& prices) {
    int max_profit = 0, min_price = INT_MAX;
    for (int p : prices) {
      min_price = std::min(min_price, p);
      max_profit = std::max(max_profit, p - min_price);
    }
    return max_profit;
  }
};
