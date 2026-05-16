// problem: https://neetcode.io/problems/permutation-string/question
// approach: sliding window, found a permutation if curr window shows all zeros
// complexity: O(26*N) = O(N) time, O(1) space, N := length s2
#include <algorithm>
#include <array>
#include <cstddef>
#include <string>

class Solution {
 public:
  bool checkInclusion (const std::string& s1, const std::string& s2) {
    std::array<int, 26> letters{};
    for (char c : s1) ++letters[c - 'a'];

    // sliding window: update s1 counter as
    // iterating through s2; if it's ever 0,
    // we found a permutation
    std::size_t l = 0;
    for (std::size_t r = 0; r < s2.size(); ++r) {
      --letters[s2[r] - 'a'];
      if (r + 1 - l > s1.size()) ++letters[s2[l++] - 'a'];
      if (std::all_of(letters.begin(), letters.end(),
                      [] (const auto& n) { return n == 0; })) return true;
    }
    return false;
  }
};
