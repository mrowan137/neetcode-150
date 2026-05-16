// problem: https://neetcode.io/problems/hand-of-straights/question
// approach: greedy; counter and start from the smallest card;
//           then loop through groups and start from smallest available card
// complexity: O(N + R) time, O(N + R) space, N := array size, R := hand value range
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool isNStraightHand (const std::vector<int>& hand, int groupSize) {
    if (hand.size()%groupSize != 0) return false;
    std::unordered_map<int, int> count;
    int start = INT_MAX, big = INT_MIN;
    for (int n : hand) {
      count[n] += 1;
      start = std::min(start, n);
      big = std::max(big, n);
    }

    for (int i = 0; i < hand.size()/groupSize; ++i) {
      // invariant: each group start at smallest card
      while (count[start] == 0 && start < big) ++start;
      for (int m = start; m < start + groupSize; ++m) {
        if (count[m] <= 0) return false;
        --count[m];
      }
    }

    return true;
  }
};
