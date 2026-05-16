// problem: https://neetcode.io/problems/combination-target-sum-ii/question
// approach: backtrack on sorted list, which allows to skip duplicates
// complexity: O(N*2^N) time, O(N) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
  void helper (const std::vector<int>& candidates, int target, int i,
               int sum, std::vector<int>& sel, std::vector<std::vector<int>>& res) {
    if (sum > target) return;
    if (sum == target) {
      res.push_back(sel);
      return;
    }
    if (i >= candidates.size()) return;

    // include
    sel.push_back(candidates[i]);
    helper(candidates, target, i + 1, sum + candidates[i], sel, res);
    sel.pop_back();

    // skip this and all duplicates
    int j = i;
    while (j < candidates.size() && candidates[j] == candidates[i]) ++j;
    helper(candidates, target, j, sum, sel, res);
  }

 public:
  std::vector<std::vector<int>> combinationSum2 (std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> sel;
    std::sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, 0, sel, res);
    return res;
  }
};
