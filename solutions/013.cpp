// problem: https://neetcode.io/problems/max-water-container/question
// approach: two pointer, explore choices by pushing the limiter
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxArea (const std::vector<int>& heights) {
    int l = 0, r = static_cast<int>(heights.size()) - 1;
    int max_area = 0;
    while (l < r) {
      max_area = std::max(max_area, std::min(heights[l], heights[r])*(r - l));
      if (heights[l] < heights[r]) ++l;  // left wall is limiter
      else --r;                          // right wall is limiter
    }
    return max_area;
  }
};
