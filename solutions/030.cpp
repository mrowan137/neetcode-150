// problem: https://neetcode.io/problems/find-minimum-in-rotated-sorted-array/question
// approach: binary search, compare last element to cut to see if in l/r of rotated array
// complexity: O(log N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  int findMin (const std::vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    int l = 0, r = n - 1;
    const int b = nums.back();
    // search for the partition;
    // compare the last element to mid;
    // search first point where it transition
    while (l <= r) {
      int mid = (l + r)/2;
      if (nums[mid] > b) l = mid + 1;
      else r = mid - 1;
    }
    return nums[l];
  }
};
