// problem: https://neetcode.io/problems/combinations-of-a-phone-number/question
// approach: backtrack on possible letters per digit
// complexity: O(N*4^N) time, O(N) space, N := length digits
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 private:
  std::unordered_map<char, std::vector<char>> phone = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
  };

  void backtrack (const std::string& digits,
                  int i, std::string& curr, std::vector<std::string>& res) {
    if (i == digits.size()) {
      // this is a result
      if (!curr.empty()) res.push_back(curr);
      return;
    }

    for (char c : phone.at(digits[i])) {
      curr += c;
      backtrack(digits, i + 1, curr, res);
      curr.pop_back();
    }
  }

 public:
  std::vector<std::string> letterCombinations (const std::string& digits) {
    std::vector<std::string> res;
    std::string curr = "";
    backtrack(digits, 0, curr, res);
    return res;
  }
};
