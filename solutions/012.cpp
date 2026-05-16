// problem: https://neetcode.io/problems/three-integer-sum/question
// approach: 1 + 2 pointer, iterate on i and left/right search j,k
// complexity: O(N^2) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum (std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());  // let us use 2-pointer
    std::vector<std::vector<int>> res;
    for (int i = 0; i + 2 < static_cast<int>(nums.size()); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int j = i + 1, k = static_cast<int>(nums.size()) - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          res.push_back({nums[i], nums[j], nums[k]});
          while (j < k && (nums[j] == nums[j + 1])) ++j;
          while (j < k && (nums[k] == nums[k - 1])) --k;
          ++j;  // need to push j and k
          --k;  // because the triplet is a sum;
                // change one necessarily means
                // the new triplet would not equal 0,
                // so might as well push both
        } else if (sum < 0) {
          ++j;
        } else {  // (sum > 0)
          --k;
        }
      }
    }
    return res;
  }
};
