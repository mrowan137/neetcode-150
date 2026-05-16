// problem: https://neetcode.io/problems/search-2d-matrix/question
// approach: binary search over number of elements
// complexity: O(log M*N) time, O(1) space, M := rows, N := cols
#include <vector>

class Solution {
 public:
  bool searchMatrix (const std::vector<std::vector<int>>& matrix, int target) {
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    int l = 0, r = m*n - 1;
    while (l <= r) {
      int mid = (l + r)/2;
      int row = mid/n;
      int col = mid%n;
      if (matrix[row][col] < target) l = mid + 1;
      else if (matrix[row][col] > target) r = mid - 1;
      else return true;
    }
    return false;
  }
};
