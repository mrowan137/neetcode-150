// problem: https://neetcode.io/problems/valid-parenthesis-string/question
// approach: greedy; check invariants for valid string, sweeping from:
//              left-to-right: l + star >= r (else, too many r)
//              right-to-left: r + star >= l (else, too many l)
//            iff invariants maintained in both sweeps, string is valid
// complexity: O(N) time, O(1) space, N := length s
#include <string>

class Solution {
 public:
  bool checkValidString (const std::string& s) {
    // character counters: opening, closing, asterisk
    int l = 0, r = 0, star = 0;

    // right-pass
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      l += c == '(';
      r += c == ')';
      star += c == '*';
      if (r > l + star) return false;
    }

    // left-pass
    l = 0, r = 0, star = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      char c = s[i];
      l += c == '(';
      r += c == ')';
      star += c == '*';
      if (l > r + star) return false;
    }

    // passed both sweeps
    return true;
  }
};
