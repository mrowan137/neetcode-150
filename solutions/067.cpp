// problem: https://neetcode.io/problems/subsets/question
// approach: backtrack to generate all sets
// complexity: O(N*2^N) time, O(N) space, N := array size
#include <vector>

class Solution {
 private:
  void helper (const std::vector<int>& nums, int i, std::vector<int>& subset,
               std::vector<std::vector<int>>& res) {
    if (i == nums.size()) {
      res.push_back(subset);
      return;
    }
    subset.push_back(nums[i]);
    helper(nums, i + 1, subset, res);
    subset.pop_back();
    helper(nums, i + 1, subset, res);
    return;
  }

 public:
  std::vector<std::vector<int>> subsets (const std::vector<int>& nums) {
    // each one has case include or exclude
    std::vector<std::vector<int>> res;
    std::vector<int> subset;
    helper(nums, 0, subset, res);
    return res;
  }
};
