// problem: https://neetcode.io/problems/count-paths/question
// approach: math; Choose(m + n - 2, m - 1); be careful of overflows
// complexity: O(N) time, O(1) space, N := min(rows, cols)
#include <algorithm>
#include <cmath>

class Solution {
 public:
  int uniquePaths (int m, int n) {
    // take n as the smallest to keep product small
    if (n > m) std::swap(m, n);

    // in a sequence of m+n-2 steps, m-1 must be
    // down and n-1 (the remaining) must be right:
    // Choose(m+n-2, m-1) := (m+n-2)!/( (m-1)! * (n-1)! )
    //                     = Product(m-1+i / i, from i=1 to n-1)
    long double res = 1.0L;  // avoid potential overflows
    for (int i = 1; i <= n - 1; ++i) {
      res = res*(m - 1 + i)/i;
    }
    return static_cast<int>(std::llround(res));
  }
};
