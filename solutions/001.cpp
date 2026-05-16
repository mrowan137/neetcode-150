// problem: https://neetcode.io/problems/duplicate-integer/question
// approach: track duplicate using a set
// complexity: O(N) time, O(N) space, N := array size
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool hasDuplicate (const std::vector<int>& nums) {
    std::unordered_set<int> s;
    for (int n : nums) {
      if (s.count(n) != 0) return true;
      s.insert(n);
    }
    return false;
  }
};
