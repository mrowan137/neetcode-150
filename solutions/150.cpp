// problem: https://neetcode.io/problems/reverse-integer/question
// approach: check for overflow/underflow res = res*10 + x%10;
//           remember in C++, % is division remainder
// complexity: O(1) time, O(1) space
#include <climits>

class Solution {
 public:
  int reverse (int x) {
    int res = 0;
    while (x) {
      if (res > INT_MAX/10 || res < INT_MIN/10) return 0;
      if ((res == INT_MAX/10 && x%10 > 7)  // INT_MAX :=  2147483647 --> overflow for 8,9
          || (res == INT_MIN/10 && x%10 == -9)) return 0;  // INT_MIN := -2147483648 --> underflow for -9
      res = res*10 + x%10;
      x /= 10;
    }
    return res;
  }
};
