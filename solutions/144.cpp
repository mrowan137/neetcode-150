// problem: https://neetcode.io/problems/single-number/question
// approach: XOR: 0^a^b^b^c^c.. == (0^a)^(b^b)^(c^c)^... == a
// complexity: O(N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  int singleNumber (const std::vector<int>& nums) {
    int res = 0;
    for (int n : nums) res ^= n;
    return res;
  }
};
