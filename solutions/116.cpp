// problem: https://neetcode.io/problems/interleaving-string/question
// approach: 2D DP; let dp[i][j] := s3 prefix formable via interleaving;
//           if s3 prefix formable from first i,j chars in s1,s2, need to ensure
//           next char in s3 matches next in s1 (from a move to right) or s2
//           (from a move downward in dp array)
// complexity: O(M*N) time, O(M*N) space, M := length s1, N := length s2
#include <string>
#include <vector>

class Solution {
 public:
  bool isInterleave (const std::string& s1, const std::string& s2, const std::string& s3) {
    const int M = s1.size();
    const int N = s2.size();

    if (M + N != s3.size()) return false;

    std::vector<std::vector<bool>> dp(M + 1, std::vector<bool>(N + 1, false));

    // initialize
    dp[0][0] = true;
    for (int j = 1; j <= N; ++j) {
      dp[0][j] = dp[0][j - 1] && (s3[j - 1] == s2[j - 1]);
    }
    for (int i = 1; i <= M; ++i) {
      dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);
    }

    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
        dp[i][j] = dp[i][j] || (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1]));
        dp[i][j] = dp[i][j] || (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
      }
    }

    return dp[M][N];
  }
};
