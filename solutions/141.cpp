// problem: https://neetcode.io/problems/pow-x-n/question
// approach: keep track of a base multiplier and iterate through bits of power
// complexity: O(log N) time, O(1) space, N := exponent magnitude

class Solution {
 public:
  double myPow (double x, int n) {
    long long p = n;  // avoid overflow if negating INT_MIN
    bool divide = p < 0;
    if (divide) p = -p;
    double res = 1.0, base = x;
    for (; p != 0; p >>= 1) {
      if (p & 1) res *= base;
      base *= base;
    }
    return divide ? 1.0/res : res;
  }
};
