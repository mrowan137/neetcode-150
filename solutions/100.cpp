// problem: https://neetcode.io/problems/min-cost-climbing-stairs/question
// approach: DP
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int minCostClimbingStairs (const std::vector<int>& cost) {
    const int N = cost.size();
    // let dp[i] := cost to reach step i
    int x = 0, y = std::min(cost[0], cost[1]);
    int z = y;
    for (int i = 3; i <= N; ++i) {
      z = std::min(x + cost[i - 2], y + cost[i - 1]);
      x = y;
      y = z;
    }

    return z;
  }
};
