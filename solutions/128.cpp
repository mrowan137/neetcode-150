// problem: https://neetcode.io/problems/partition-labels/question
// approach: greedy; we can split when no letters from the current substring are in the remaining;
//           track those in the current substring, and when none remain in remainder string (using counter), w/ bitmask
// complexity: O(N) time, O(1) space, N := length s
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> partitionLabels (const std::string& s) {
    // when can we split? only when there's no
    // letters from current substring in remainder
    std::vector<int> res;
    std::unordered_map<char, int> count;
    int len = 0;
    for (char c : s) count[c] += 1;
    std::uint32_t tmp = 0x0u;
    for (char c : s) {
      len += 1;
      --count[c];
      tmp |= (0x1u << (c - 'a'));
      if (count[c] == 0) tmp ^= (0x1u << (c - 'a'));
      if (tmp == 0x0u) {
        res.push_back(len);
        len = 0;
        tmp = 0x0u;
      }
    }
    return res;
  }
};
