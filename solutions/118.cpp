// problem: https://neetcode.io/problems/count-subsequences/question
// approach: 2D DP; new matches can come from dp[i-1][j-1] by
//           appending the new matching letter, the previous
//           matches dp[i][j-1] come along for the ride
// complexity: O(M*N) time, O(M*N) space, M := length t, N := length s
#include <string>
#include <vector>

class Solution {
 public:
  int numDistinct (const std::string& s, const std::string& t) {
    const int M = t.size();
    const int N = s.size();

    // let dp[i][j] := number of distinct subsequences s[:j] equal to t[:i]
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0));

    // init: can always form empty string by deleting all chars in s
    for (int j = 0; j <= N; ++j) dp[0][j] = 1;

    // fill
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
        dp[i][j] = dp[i][j - 1];
        if (t[i - 1] == s[j - 1]) dp[i][j] += dp[i - 1][j - 1];
      }
    }

    return dp[M][N];
  }
};
