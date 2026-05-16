// problem: https://neetcode.io/problems/number-of-one-bits/question
// approach: count 1 bits through folding
// complexity: O(1) time, O(1) space
#include <cstdint>

class Solution {
 public:
  int hammingWeight (std::uint32_t n) {
    std::uint32_t res = n;  // accumulate counts through folding
    res = (res & 0x55555555u) + ((res & 0xAAAAAAAAu) >> 1);
    res = (res & 0x33333333u) + ((res & 0xCCCCCCCCu) >> 2);
    res = (res & 0x0F0F0F0Fu) + ((res & 0xF0F0F0F0u) >> 4);
    res = (res & 0x00FF00FFu) + ((res & 0xFF00FF00u) >> 8);
    res = (res & 0x0000FFFFu) + ((res & 0xFFFF0000u) >> 16);
    return static_cast<int>(res);
  }
};
