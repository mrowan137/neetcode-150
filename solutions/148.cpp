// problem: https://neetcode.io/problems/missing-number/question
// approach: XOR: repeats cancel, leaving the singleton
// complexity: O(N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  int missingNumber (const std::vector<int>& nums) {
    int res = 0;
    for (int i = 0; i <= nums.size(); ++i) res ^= i;
    for (int n : nums) res ^= n;
    return res;
  }
};
