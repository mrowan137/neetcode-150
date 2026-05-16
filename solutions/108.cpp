// problem: https://neetcode.io/problems/word-break/question
// approach: DP; consider which states are reachable using dictionary words
// complexity: O(M*N*T) time, O(N) space, M := num words in wordDict,
//             N := length s, T := max length any word in wordDict
#include <string>
#include <vector>

class Solution {
 public:
  bool wordBreak (const std::string& s, const std::vector<std::string>& wordDict) {
    const int N = s.size();
    std::vector<bool> dp(N + 1, false);  // dp[i] := position i-1 in s is reachable
    dp[0] = 1;

    for (int i = 1; i < N + 1; ++i) {
      for (const std::string& w : wordDict) {
        if (i >= w.size() && w == s.substr(i - w.size(), w.size()) && dp[i - w.size()]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[N];
  }
};
