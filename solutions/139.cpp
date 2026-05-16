// problem: https://neetcode.io/problems/non-cyclical-number/question
// approach: fast and slow pointers
// complexity: O(log N) time, O(1) space, N := value

class Solution {
 public:
  bool isHappy (int n) {
    auto step = [] (int m) {
      int res = 0;
      for (; m; m /= 10) res += (m%10)*(m%10);
      return res;
    };

    int fast = n, slow = n;
    while (true) {  // by assumption, number is happy or cyclical
      fast = step(fast);
      if (fast == 1) return true;
      fast = step(fast);
      slow = step(slow);
      if (slow == fast) return false;
    }
  }
};
