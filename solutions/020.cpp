// problem: https://neetcode.io/problems/sliding-window-maximum/question
// approach: sliding window + multiset to maintain sorted window
// complexity: O(N log K) time, O(K) space, N := array size, K := window size
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow (const std::vector<int>& nums, int k) {
    std::vector<int> res;
    std::multiset<int> ns;
    int l = 0;
    for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
      ns.insert(nums[r]);
      if (r - l + 1 > k) ns.erase(ns.find(nums[l++]));
      if (static_cast<int>(ns.size()) == k) res.push_back(*ns.rbegin());
    }
    return res;
  }
};
