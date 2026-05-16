// problem: https://neetcode.io/problems/products-of-array-discluding-self/question
// approach: two passes to accumulate left and right products
// complexity: O(N) time, O(1) space, N := array size
#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf (const std::vector<int>& nums) {
    const int N = static_cast<int>(nums.size());
    std::vector<int> res(N, 1);

    // left pass: product everything LEFT of me
    for (int i = 1; i < N; ++i) {
      res[i] = res[i - 1]*nums[i - 1];
    }

    // right pass: product everything RIGHT of me
    int r = 1;
    for (int i = N - 1; i >= 0; --i) {
      res[i] *= r;
      r *= nums[i];
    }
    return res;
  }
};
