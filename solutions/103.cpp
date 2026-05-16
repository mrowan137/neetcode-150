// problem: https://neetcode.io/problems/longest-palindromic-substring/question
// approach: scan outward from any fence/post that can be center of palindrome
// complexity: O(N^2) time, O(1) space, N := length s
#include <string>
#include <utility>

class Solution {
 public:
  std::string longestPalindrome (const std::string& s) {
    // consider all 2n-1 positions
    const int N = s.size();

    auto palindrome = [&] (int l, int r) {
      // iterate until out of bounds or no match
      while (l >= 0 && r < N && s[l] == s[r]) {
        --l; ++r;
      }
      return std::pair<int, int>({l + 1, r - 1});
    };

    int longest = 0;
    std::string res = "";
    for (int i = 0; i < 2*N - 1; ++i) {
      int start = i/2, end = i/2 + i%2;
      auto [l, r] = palindrome(start, end);
      if ((r - l + 1) > longest) {
        longest = r - l + 1;
        res = s.substr(l, longest);
      }
    }
    return res;
  }
};
