// problem: https://neetcode.io/problems/validate-parentheses/question
// approach: stack, close matches on the fly
// complexity: O(N) time, O(N) space, N := length s
#include <stack>
#include <string>

class Solution {
 public:
  bool matches (char o, char c) {
    return (o == '(' && c == ')')
           || (o == '[' && c == ']')
           || (o == '{' && c == '}');
  }

  bool isValid (const std::string& s) {
    std::stack<char> stk;
    std::string opens = "({[";
    for (char c : s) {
      if (opens.find(c) != std::string::npos) {
        stk.push(c);
      } else {
        if (stk.empty() || !matches(stk.top(), c)) return false;
        stk.pop();
      }
    }
    return stk.empty();  // every open pair to a close
  }
};
