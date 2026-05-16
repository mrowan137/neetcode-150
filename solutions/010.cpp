// problem: https://neetcode.io/problems/is-palindrome/question
// approach: two pointer, check from left and right
// complexity: O(N) time, O(1) space, N := length s
#include <cctype>
#include <cstddef>
#include <string>

class Solution {
 public:
  bool isPalindrome (const std::string& s) {
    if (s.empty()) return true;
    std::size_t i = 0, j = s.size() - 1;
    while (i < j) {
      // skip non alpha-numeric
      while (i < j && !std::isalnum(s[i])) ++i;
      while (j > i && !std::isalnum(s[j])) --j;
      if (i < j && std::tolower(s[i++]) != std::tolower(s[j--])) {
        return false;
      }
    }
    return true;
  }
};
