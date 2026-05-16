// problem: https://neetcode.io/problems/edit-distance/question
// approach: 2D DP; match source to target by add to source, remove from source,
//           or advance source & target, replacing if no match
// complexity: O(M*N) time, O(M*N) space, M := length word2, N := length word1
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minDistance (const std::string& word1, const std::string& word2) {
    const int M = word2.size();
    const int N = word1.size();

    // let dp[i][j] := number of ops to transform word1[:j] into word2[:i]
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0));

    // init: turn word1 into empty string by deleting every letter,
    // or empty string into word2 by inserting letter
    for (int j = 1; j <= N; ++j) dp[0][j] = j;
    for (int i = 1; i <= M; ++i) dp[i][0] = i;

    for (int i = 1; i <= M; ++i) {  // word2, target
      for (int j = 1; j <= N; ++j) {  // word1, source
        // word1 can match to word2 by:
        //  delete: dp[i][j-1] match, remove letter in word1
        //  insert: dp[i-1][j] match, add a letter to word1
        //  replace: dp[i-1][j-1] match, replace if letters don't match
        dp[i][j] = std::min({dp[i][j - 1] + 1,
                             dp[i - 1][j] + 1,
                             dp[i - 1][j - 1] + (word1[j - 1] != word2[i - 1] ? 1 : 0)});
      }
    }

    return dp[M][N];
  }
};
