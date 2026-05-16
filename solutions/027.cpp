// problem: https://neetcode.io/problems/binary-search/question
// approach: iteratively bisect and explore target section
// complexity: O(log N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  int search (const std::vector<int>& nums, int target) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l <= r) {
      int mid = (l + r)/2;
      if (nums[mid] > target) r = mid - 1;
      else if (nums[mid] < target) l = mid + 1;
      else return mid;
    }
    return -1;
  }
};
