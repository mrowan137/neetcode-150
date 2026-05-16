// problem: https://neetcode.io/problems/plus-one/question
// approach: the addition algorithm from elementary school: maintain a carry
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> plusOne (const std::vector<int>& digits) {
    int carry = 1;
    std::vector<int> res;
    for (int i = digits.size() - 1; i >= 0; --i) {
      res.push_back((digits[i] + carry)%10);
      carry = (digits[i] + carry)/10;
    }
    if (carry != 0) res.push_back(carry);
    std::reverse(res.begin(), res.end());
    return res;
  }
};
