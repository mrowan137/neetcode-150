// problem: https://neetcode.io/problems/merge-triplets-to-form-target/question
// approach: greedy; only include triplets that help
// complexity: O(N) time, O(1) space, N := array size triplets
#include <algorithm>
#include <vector>

class Solution {
 public:
  bool mergeTriplets (const std::vector<std::vector<int>>& triplets, const std::vector<int>& target) {
    std::vector<int> tmp(3, 0);
    for (const auto& t : triplets) {
      if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
      tmp[0] = std::max(tmp[0], t[0]);
      tmp[1] = std::max(tmp[1], t[1]);
      tmp[2] = std::max(tmp[2], t[2]);
      if (tmp == target) return true;
    }
    return false;
  }
};
