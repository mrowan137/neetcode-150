// problem: https://neetcode.io/problems/eating-bananas/question
// approach: binary search the rate from [1, max(piles)]
// complexity: O(N log M) time, O(1) space, N := array size, M := array max
#include <algorithm>
#include <vector>

class Solution {
 private:
  bool eatable (const std::vector<int>& piles, int h, int k) {
    int t = 0;
    for (int p : piles) {
      t += p%k == 0 ? p/k : p/k + 1;
      if (t > h) return false;
    }
    return true;
  }

 public:
  int minEatingSpeed (const std::vector<int>& piles, int h) {
    // we know k is bounded by [1, max(piles)]
    // as long as h >= len(piles)
    // because then we can finish each stack in an hour
    // so if h is larger, k can be less. binary search
    // for the smallest allowable k.
    int l = 1;
    int r = *std::max_element(piles.begin(), piles.end());
    while (l <= r) {
      int mid = (l + r)/2;
      if (eatable(piles, h, mid)) r = mid - 1;
      else l = mid + 1;
    }
    return l;
  }
};
