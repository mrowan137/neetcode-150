// problem: https://neetcode.io/problems/is-anagram/question
// approach: encode counts and compare across strings
// complexity: O(N + M) time, O(1) space, N := length s, M := length t
#include <cstddef>
#include <string>

class Solution {
 public:
  bool isAnagram (const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    char letters[26] = {};
    for (std::size_t i = 0; i < s.size(); ++i) {
      ++letters[s[i] - 'a'];
      --letters[t[i] - 'a'];
    }
    for (std::size_t i = 0; i < 26; ++i) {
      if (letters[i] != 0) return false;
    }
    return true;
  }
};
