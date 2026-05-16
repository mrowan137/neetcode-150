// problem: https://neetcode.io/problems/palindromic-substrings/question
// approach: number of palindromes at a position is half-length of longest at that position
// complexity: O(N^2) time, O(1) space, N := length s
#include <string>
#include <utility>

class Solution {
 public:
  int countSubstrings (const std::string& s) {
    const int N = s.size();

    auto palindrome = [&](int l, int r) {
      while (l >= 0 && r < N && s[l] == s[r]) {
        ++r;
        --l;
      }
      return std::pair<int, int>({l + 1, r - 1});
    };

    int res = 0;
    for (int i = 0; i < 2*N - 1; ++i) {
      int start = i/2;
      int end = i/2 + i%2;
      auto [l, r] = palindrome(start, end);
      // count of palindromes at this position
      // (half-length rounded up)
      res += (r - l + 1)/2 + (i + 1)%2;
    }

    return res;
  }
};
