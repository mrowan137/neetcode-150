// problem: https://neetcode.io/problems/evaluate-reverse-polish-notation/question
// approach: use stack to collapse expressions on the fly
// complexity: O(N) time, O(N) space, N := array size
#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  int evalRPN (const std::vector<std::string>& tokens) {
    std::stack<int> s;
    for (const std::string& t : tokens) {
      std::string ops = "+-*/";
      if (t.size() == 1 && (ops.find(t) != std::string::npos)) {  // operation
        int y = s.top(); s.pop();
        int x = s.top(); s.pop();
        switch (t[0]) {
          case '+': s.push(x + y); break;
          case '-': s.push(x - y); break;
          case '*': s.push(x*y); break;
          case '/': s.push(x/y); break;
        }
      } else {  // operand
        s.push(std::stoi(t));
      }
    }
    return s.top();
  }
};
