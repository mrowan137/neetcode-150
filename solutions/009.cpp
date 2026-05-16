// problem: https://neetcode.io/problems/longest-consecutive-sequence/question
// approach: if num is beginning of a sequence, count length
// complexity: O(N) time, O(N) space, N := array size
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int longestConsecutive (const std::vector<int>& nums) {
    std::unordered_set<int> s;
    for (int n : nums) s.insert(n);

    int longest = 0;
    for (int n : nums) {
      if (s.find(n - 1) == s.end()) {
        int m = n;
        while (s.find(m) != s.end()) ++m;
        longest = std::max(longest, m - n);
      }
    }
    return longest;
  }
};
