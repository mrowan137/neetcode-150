// problem: https://neetcode.io/problems/decode-ways/question
// approach: rolling DP; each position can be the end of a one- or two-digit number
// complexity: O(N) time, O(1) space, N := length s
#include <string>

class Solution {
 public:
  int numDecodings (const std::string& s) {
    const int N = s.size();
    // Rolling dp:
    // let dp[i] := number of ways to
    // decode string ending at index i;
    // each char can be end of 1-digit,
    // end of a 2-digit, or both
    auto one_digit = [&] (int d) {
      return 1 <= d && d <= 9;
    };
    auto two_digit = [&] (int d) {
      return (10 <= d && d <= 26);
    };

    int x = 1, y = one_digit(s[0] - '0'), ways = 0;
    if (s.size() == 1) return y;
    for (int i = 1; i < N; ++i) {
      ways = 0;
      if (one_digit(s[i] - '0')) ways += y;
      if (two_digit( (s[i - 1] - '0')*10 + (s[i] - '0') )) ways += x;
      x = y;
      y = ways;
    }
    return ways;
  }
};
