// problem: https://neetcode.io/problems/combination-target-sum/question
// approach: backtrack, include or exclude contribs to target
// complexity: O(exponential ~K) time, O(K) space, K := target/min(nums)
#include <vector>

class Solution {
 private:
  void helper (const std::vector<int>& nums, int target, int i,
               std::vector<int>& selection, std::vector<std::vector<int>>& res) {
    if (i >= nums.size() || target < 0) return;
    if (target == 0) {
      res.push_back(selection);
      return;
    }

    // choices: include or not include; max depth of search is target/min(nums),
    // from which we explore self-similar states so that the search space is
    // exponential in target/min(nums)
    selection.push_back(nums[i]);
    helper(nums, target - nums[i], i, selection, res);
    selection.pop_back();
    helper(nums, target, i + 1, selection, res);
  }

 public:
  std::vector<std::vector<int>> combinationSum (const std::vector<int>& nums, int target) {
    std::vector<int> sel;
    std::vector<std::vector<int>> res;
    helper(nums, target, 0, sel, res);
    return res;
  }
};
