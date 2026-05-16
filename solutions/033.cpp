// problem: https://neetcode.io/problems/median-of-two-sorted-arrays/question
// approach: binary search in shorter array, determines cut in other
// complexity: O(log(min(M, N))) time, O(1) space, M := array size nums1, N := array size nums2
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays (const std::vector<int>& nums1, const std::vector<int>& nums2) {
    // binary search in the shorter array
    // then the cut in 2nd array is determined (and valid)
    // so we partition two arrays into parts:
    //   {L1} | {R1}
    //   {L2} | {R2}
    // by construction ||{L1} U {L2}| - |{R1} U {R2}|| <= 1.
    // we know we have the median element when
    //   L1[-1] < R2[0] && L2[-1] < R1[0]
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    const int m = static_cast<int>(nums1.size());
    const int n = static_cast<int>(nums2.size());
    const int hlf = (m + n)/2;
    int l = 0, r = m;  // search the number of elements in nums1
                       // to contribute to the left set

    while (l <= r) {
      int mid = (l + r)/2;
      int c1R = mid;
      int c1L = c1R - 1;
      int c2R = hlf - mid;
      int c2L = c2R - 1;
      int n1L = c1L >= 0 ? nums1[c1L] : INT_MIN;
      int n1R = c1R <  m ? nums1[c1R] : INT_MAX;
      int n2L = c2L >= 0 ? nums2[c2L] : INT_MIN;
      int n2R = c2R <  n ? nums2[c2R] : INT_MAX;
      if (n1L > n2R) r = mid - 1;
      else if (n2L > n1R) l = mid + 1;
      else return (m + n) %2 == 0 ? 0.5*(std::min(n1R, n2R) + std::max(n1L, n2L))
                                  : ( (c1R + c2R) > hlf ? std::max(n1L, n2L)
                                                        : std::min(n1R, n2R));
    }
    return 0.0;  // shouldn't get here
  }
};
