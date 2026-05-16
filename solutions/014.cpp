// problem: https://neetcode.io/problems/trapping-rain-water/question
// approach v2: two pointer, greedy move to the next limiter
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int trap (const std::vector<int>& height) {
    // contribution from each idx is limited
    // by max on the left, max on the right
    int l = 0, r = static_cast<int>(height.size()) - 1;
    int left_max = height[0];
    int right_max = height[static_cast<int>(height.size()) - 1];
    int total = 0;

    while (l < r) {
      // invariant: when height[l] < height[r],
      // left_max < right_max, defining the limiter
      if (height[l] < height[r]) {
        left_max = std::max(left_max, height[l]);
        total += left_max - height[l++];
      } else {
        right_max = std::max(right_max, height[r]);
        total += right_max - height[r--];
      }
    }
    return total;
  }
};

// approach v1: two pass, store max on left and right to get limiter
// complexity: O(N) time, O(N) space, N := array size
class SlowSolution {
 public:
  int trap (const std::vector<int>& height) {
    const int N = static_cast<int>(height.size());
    std::vector<int> l(N + 1, 0);  // maxes on left
    std::vector<int> r(N + 1, 0);  // max from right

    int m = INT_MIN;
    for (int i = 0; i < N; ++i) {
      m = std::max(m, height[i]);
      l[i + 1] = m;
    }

    m = INT_MIN;
    for (int i = N - 1; i >= 0; --i) {
      m = std::max(m, height[i]);
      r[i] = m;
    }

    int res = 0;
    for (int i = 0; i < N; ++i) {
      res += std::max(std::min(l[i + 1], r[i]) - height[i], 0);
    }
    return res;
  }
};
