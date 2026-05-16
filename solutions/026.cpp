// problem: https://neetcode.io/problems/largest-rectangle-in-histogram/question
// approach: stack, collapse candidate contributions when hit a decrease in height
// complexity: O(N) time, O(N) space, N := array size
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  int largestRectangleArea (const std::vector<int>& heights) {
    std::stack<int> s;  // store the indices to compute width
    int max_area = 0;
    // accumulate indices of increasing heights into s
    // when we hit a decrease, calculate all
    // candidates' contribution -- we can process anything
    // bounded on the left and right w.r.t. height, i.e.
    // as long as heights[i] < heights[s.top()]

    // invariant: stack has indices of non-decreasing heights;
    // since it's non-decreasing, the width is bounded from current i,
    // and idx to left in the stack -- indices w/ larger heights could
    // have been popped, but they still contribute to blocks area
    for (int i = 0; i < static_cast<int>(heights.size()); ++i) {
      // hit a decrease, process the stack
      while (!s.empty() && heights[i] < heights[s.top()]) {
        int h = heights[s.top()]; s.pop();
        int w = s.empty() ? i : i - s.top() - 1;
        max_area = std::max(max_area, h*w);
      }
      s.push(i);
    }

    // final cleanup -- stack could still be full
    while (!s.empty()) {
      int h = heights[s.top()]; s.pop();
      int w = s.empty() ? static_cast<int>(heights.size())
                        : static_cast<int>(heights.size()) - s.top() - 1;
      max_area = std::max(max_area, h*w);
    }
    return max_area;
  }
};
