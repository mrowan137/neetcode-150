// problem: https://neetcode.io/problems/permutations/question
// approach: backtrack, maintaining remaining valid picks
// complexity: O(N*N!) time, O(N) space, N := array size
#include <vector>

class Solution {
 private:
  void helper (const std::vector<int>& nums, std::vector<bool>& rem,
               int i, std::vector<int>& p, std::vector<std::vector<int>>& res) {
    if (i >= nums.size()) {
      res.push_back(p);
      return;
    }
    // choose one from remaining to be the front
    for (int j = 0; j < nums.size(); ++j) {
      if (rem[j]) {
        p.push_back(nums[j]);
        rem[j] = false;
        helper(nums, rem, i + 1, p, res);
        rem[j] = true;
        p.pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<int>> permute (const std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> p;
    std::vector<bool> remaining(nums.size(), true);
    helper(nums, remaining, 0, p, res);
    return res;
  }
};
