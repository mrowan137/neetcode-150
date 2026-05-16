// problem: https://neetcode.io/problems/generate-parentheses/question
// approach: backtracking to explore pruned tree of possible parens expressions
// complexity: O(N*4^N) time, O(N) space, N := num paren pairs
#include <string>
#include <vector>

class Solution {
 private:
  std::vector<std::string> ret{};
  void generate (int l, int r, int n, std::string& s) {
    if (l == n && r == n) {
      ret.push_back(s);
      return;
    }
    if (l < n) {
      s.push_back('(');
      generate(l + 1, r, n, s);
      s.pop_back();
    }
    if (r < l) {
      s.push_back(')');
      generate(l, r + 1, n, s);
      s.pop_back();
    }
  }

 public:
  std::vector<std::string> generateParenthesis (int n) {
    // what it means to be well formed:
    // let l := number of left parens
    //     r := number of right parens
    // then cumulative sum of r <= l
    // at any point in the string
    std::string parens = "";
    generate(0, 0, n, parens);
    return ret;
  }
};
