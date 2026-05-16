// problem: https://neetcode.io/problems/longest-repeating-substring-with-replacement/question
// approach v2: freeze & drag sliding window, expand only if greater max freq is found
// complexity: O(N) time, O(1) space, N := length s
#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int characterReplacement (const std::string& s, int k) {
    // decompose your string into a max_freq
    // and k others, for replacement
    // maintain invariant:
    //   r + 1 - l <= max_freq + k
    // where max_freq := the greatest
    // freq we ever saw in the window [l, r + 1]
    int l = 0;
    int longest = 0;
    std::unordered_map<char, int> freqs;
    int max_freq = 0;
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
      max_freq = std::max(max_freq, ++freqs[s[r]]);
      if (r + 1 - l > max_freq + k) --freqs[s[l++]];
      longest = std::max(longest, r + 1 - l);
    }
    return longest;
  }
};

// approach v1: iterate and maintain invariant, max_freq + k <= window size
// complexity: O(26*N) = O(N) time, O(1) space, N := length s
class AltSolution {
 public:
  int characterReplacement (const std::string& s, int k) {
    int i = 0, j = 0;
    int longest = 0;
    std::unordered_map<char, int> freqs;

    // in a given range [i , j], maintain invariant:
    // j - i <= max(freq) + k
    while (j < static_cast<int>(s.size())) {
      ++freqs[s[j++]];
      auto m_it = std::max_element(freqs.begin(), freqs.end(),
                                   [] (const auto& x, const auto& y) {
                                     return x.second < y.second;
                                   });
      int m_val = m_it->second;

      while ( i < j && ((j - i) > (m_val + k)) ) {
        --freqs[s[i++]];
        m_it = std::max_element(freqs.begin(), freqs.end(),
                                [] (const auto& x, const auto& y) {
                                  return x.second < y.second;
                                });
        m_val = m_it->second;
      }
      longest = std::max(longest, j - i);
    }

    return longest;
  }
};
