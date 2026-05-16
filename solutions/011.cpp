// problem: https://neetcode.io/problems/two-integer-sum-ii/question
// approach: two pointer, search target sum by narrowing left/right
// complexity: O(N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum (const std::vector<int>& numbers, int target) {
    int i = 0, j = static_cast<int>(numbers.size()) - 1;
    while (i < j) {
      int tot = numbers[i] + numbers[j];
      if (tot == target) return {i + 1, j + 1};

      if (tot > target) --j;
      else ++i;
    }
    return {};
  }
};
