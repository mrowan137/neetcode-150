// problem: https://neetcode.io/problems/target-sum/question
// approach: don't know the range of sum (it can exceed target or go negative), so use a map;
//           use two maps per iteration to track current and previous;
//           swap, clear current, and expand all states in previous
// complexity: O(N*M) time, O(M) space, N := array size, M := sum of array elements
#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findTargetSumWays (const std::vector<int>& nums, int target) {
    // let curr[i] := number of ways to reach target, using
    // nums up to n_j (single-use enforce by loop over nums);
    // we don't know range of sums so use a map
    std::unordered_map<int, int> curr, prev;
    curr[0] = 1;  // one way to reach sum of 0
    for (int n : nums) {
      std::swap(prev, curr);  // copy disallows repeat use of n_j
      curr.clear();  // clear isolates dp to current layer
      for (auto& [sum, count] : prev) {
        curr[sum - n] += count;
        curr[sum + n] += count;
      }
    }
    return curr[target];
  }
};
