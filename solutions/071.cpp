// problem: https://neetcode.io/problems/subsets-ii/question
// approach: backtrack on sorted nums, skip duplicates
// complexity: O(N*2^N) time, O(N) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 private:
  void helper (std::vector<int>& nums,
               int i,
               std::vector<int>& sel,
               std::vector<std::vector<int>>& res) {
    if (i >= nums.size()) {
      res.push_back(sel);
      return;
    }
    // include ith
    sel.push_back(nums[i]);
    helper(nums, i + 1, sel, res);
    sel.pop_back();

    // skip
    int j = i;
    while (j < nums.size() && nums[i] == nums[j]) ++j;
    helper(nums, j, sel, res);
  }

 public:
  std::vector<std::vector<int>> subsetsWithDup (std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> sel;
    std::sort(nums.begin(), nums.end());
    helper(nums, 0, sel, res);
    return res;
  }
};
