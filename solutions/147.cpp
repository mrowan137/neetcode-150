// problem: https://neetcode.io/problems/reverse-bits/question
// approach: reverse bits by swapping halves, quarters, etc.
// complexity: O(1) time, O(1) space
#include <cstdint>

class Solution {
 public:
  std::uint32_t reverseBits (std::uint32_t n) {
    std::uint32_t res = n;
    res = (0x0000FFFFu & res)<<16 | (0xFFFF0000u & res) >> 16;
    res = (0x00FF00FFu & res)<<8  | (0xFF00FF00u & res) >> 8;
    res = (0x0F0F0F0Fu & res)<<4  | (0xF0F0F0F0u & res) >> 4;
    res = (0x33333333u & res)<<2  | (0xCCCCCCCCu & res) >> 2;
    res = (0x55555555u & res)<<1  | (0xAAAAAAAAu & res) >> 1;
    return res;
  }
};
