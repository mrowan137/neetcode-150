// problem: https://neetcode.io/problems/find-target-in-rotated-sorted-array/question
// approach: binary search, find element then search left or right accordingly
// complexity: O(log N) time, O(1) space, N := array size
#include <vector>

class Solution {
 private:
  int bs (const std::vector<int>& nums, int target, int l, int r) {
    while (l <= r) {
      int mid = (l + r)/2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }

 public:
  int search (const std::vector<int>& nums, int target) {
    // find min element, then search whichever
    // range contains target
    const int b = nums.back();
    const int n = static_cast<int>(nums.size());
    int l = 0, r = n - 1;

    while (l <= r) {
      int mid = (l + r)/2;
      if (nums[mid] > b) l = mid + 1;
      else r = mid - 1;
    }
    int small = nums[l];
    int i, j;
    if (target >= small && target <= b) {
      // search right
      i = l;
      j = n - 1;
    } else {
      // search left
      i = 0;
      j = l - 1;
    }
    return bs(nums, target, i, j);
  }
};
