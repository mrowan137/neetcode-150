// problem: https://neetcode.io/problems/longest-substring-without-duplicates/question
// approach: sliding window and counter, push left until no repeats
// complexity: O(N) time, O(N) space, N := length s
#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring (const std::string& s) {
    // if r shows a repeat, push l until none
    int l = 0;
    int longest = 0;
    std::unordered_map<char, int> freqs;
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
      freqs[s[r]] += 1;
      while (freqs[s[r]] > 1) --freqs[s[l++]];
      // invariant: l,r point to valid ends of non-repeat substring
      longest = std::max(longest, r - l + 1);
    }
    return longest;
  }
};
