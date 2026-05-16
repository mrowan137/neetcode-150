// problem: https://neetcode.io/problems/palindrome-partitioning/question
// approach: backtrack on any palindrome
// complexity: O(N^2*2^N) time, O(N) space, N := length s
#include <string>
#include <vector>

class Solution {
 private:
  bool is_palindrome (const std::string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) return false;
    }
    return true;
  }

  void backtrack (const std::string& s,
                  int i,
                  std::vector<std::string>& curr,
                  std::vector<std::vector<std::string>>& res) {
    // goal: break it into all palindrome
    if (i == s.size()) {
      res.push_back(curr);
      return;
    }

    // consider each remaining positions as a palindrome
    for (int j = i; j < s.size(); ++j) {
      if (is_palindrome(s, i, j)) {
        curr.push_back(s.substr(i, j - i + 1));
        backtrack(s, j + 1, curr, res);
        curr.pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<std::string>> partition (const std::string& s) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> curr;

    backtrack(s, 0, curr, res);

    return res;
  }
};
