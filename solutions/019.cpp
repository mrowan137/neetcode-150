// problem: https://neetcode.io/problems/minimum-window-with-characters/question
// approach v2: sliding window, shrink while valid using 128-array
// complexity: O(128*N) time, O(1) space, N := length s
#include <array>
#include <string>
#include <unordered_map>

class Solution {
 public:
  bool has_all (const std::array<int, 128>& reference_letters,
                const std::array<int, 128>& compare_letters) {
    for (int i = 0; i < 128; ++i) {
      if (reference_letters[i] > compare_letters[i]) {
        return false;
      }
    }
    return true;
  }

  std::string minWindow (const std::string& s, const std::string& t) {
    std::array<int, 128> t_letters{};
    for (char c : t) ++t_letters[c];

    int l = 0;
    std::array<int, 128> s_letters{};
    std::string res = "";
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
      ++s_letters[s[r]];
      while (has_all(t_letters, s_letters)) {
        if (res.empty() || r - l + 1 < static_cast<int>(res.size())) {
          res = s.substr(l, r - l + 1);
        }
        --s_letters[s[l++]];
      }
    }
    return res;
  }
};

// approach v1: sliding window, shrink while valid using map
// complexity: O(N*M) time, O(1) space, N := length s, M := length t
class SlowSolution {
 private:
  bool has_all (std::unordered_map<char, int>& s,
                std::unordered_map<char, int>& t) {
    for (const auto& kv : t) {
      if (s[kv.first] < t[kv.first]) return false;
    }
    return true;
  }

 public:
  std::string minWindow (const std::string& s, const std::string& t) {
    // sliding window: iterate through s,
    // expand window; while contains all of t,
    // shrink the window
    std::unordered_map<char, int> t_cnt;
    std::unordered_map<char, int> s_cnt;

    // fill reference
    for (char c : t) t_cnt[c] += 1;

    int l = 0;
    std::string res = "";
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
      s_cnt[s[r]] += 1;
      while (has_all(s_cnt, t_cnt)) {
        std::string candidate = s.substr(l, r - l + 1);
        if (res.empty()) {
          res = candidate;
        } else {
          res = candidate.size() < res.size() ? candidate : res;
        }
        --s_cnt[s[l++]];
      }
    }
    return res;
  }
};
