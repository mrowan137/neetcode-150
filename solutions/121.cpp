// problem: https://neetcode.io/problems/regular-expression-matching/question
// approach: 2D DP; case 1, p[j-1] == '*': skip p[j-1] and p[j-2], or consume a char in s
//                  case 2, p[j-1] == '.': s,p match to i-1,j-1
//                  case 3, s[i-1] == p[j-1]: s,p match to i-1,j-1
// complexity: O(M*N) time, O(M*N) space, M := length s, N := length p
#include <string>
#include <vector>

class Solution {
 public:
  bool isMatch (const std::string& s, const std::string& p) {
    const int M = s.size();
    const int N = p.size();

    // let dp[i][j] := s,p match up to i-1,j-1
    std::vector<std::vector<bool>> dp(M + 1, std::vector<bool>(N + 1, false));

    // initialize
    dp[0][0] = true;
    for (int j = 2; j <= N; ++j) {  // catch edge case like s="", p="a*a*a*"
      if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    }

    // fill
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = (dp[i][j - 2]  // repeat 0 times or consume a char in s
                      || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')));
        } else if (p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
        }
      }
    }

    return dp[M][N];
  }
};
