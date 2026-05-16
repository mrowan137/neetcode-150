// problem: https://neetcode.io/problems/longest-common-subsequence/question
// approach: 2D DP; case 1: letters match --> extend diagonal;
//                  case 2: letters not match --> take best of up, left
// complexity: O(M*N) time, O(M*N) space, M := length text1, N := length text2
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int longestCommonSubsequence (const std::string& text1, const std::string& text2) {
    const int M = text1.size();
    const int N = text2.size();

    // let dp[i][j] := longest common subseq up to i,j in text1,text2
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0));

    for (int i = 1; i <= M; ++i) {
      // for a given row, fill out all the cols
      // thus we can assume that dp[i-1][j] is complete
      for (int j = 1; j <= N; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          // case 1: char match
          dp[i][j] = dp[i - 1][j - 1] + 1 ;
        } else {
          // case 2: char not match
          dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[M][N];
  }
};
