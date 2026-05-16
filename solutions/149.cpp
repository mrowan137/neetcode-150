// problem: https://neetcode.io/problems/sum-of-two-integers/question
// approach: iteratively combine partial sum and carry until no more carry
// complexity: O(1) time, O(1) space
#include <cstdint>

class Solution {
 public:
  int getSum (int a, int b) {
    std::uint32_t x = static_cast<std::uint32_t>(a);
    std::uint32_t y = static_cast<std::uint32_t>(b);

    while (y != 0) {
      std::uint32_t carry = (x & y) << 1;
      x = x ^ y;
      y = carry;
    }

    return static_cast<int>(x);
  }
};
