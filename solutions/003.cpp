// problem: https://neetcode.io/problems/two-integer-sum/question
// approach: track differences in a map
// complexity: O(N) time, O(N) space, N := array size
#include <cstddef>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum (const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> m;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      if (m.find(target - nums[i]) != m.end()) {
        return {m[target - nums[i]], static_cast<int>(i)};
      }
      m[nums[i]] = i;
    }
    return {};
  }
};
