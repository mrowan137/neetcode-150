// problem: https://neetcode.io/problems/anagram-groups/question
// approach: group by common letter-based encoding
// complexity: O(N) time, O(M + N) space, N := total chars, M := num strings
#include <array>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 private:
  void encode (const std::string& s, std::array<std::size_t, 26>& a) {
    for (auto c : s) ++a[c - 'a'];
  }

  struct HashFunctor {
    std::size_t operator() (const std::array<std::size_t, 26>& a) const noexcept {
      std::size_t res = 0;
      for (auto n : a) {
        res *= 31;
        res += n;
      }
      return res;
    }
  };

 public:
  std::vector<std::vector<std::string>> groupAnagrams (const std::vector<std::string>& strs) {
    std::unordered_map<std::array<std::size_t, 26>,
                       std::vector<std::string>,
                       HashFunctor> m;

    for (const auto& s : strs) {
      std::array<std::size_t, 26> a{};
      encode(s, a);
      m[a].push_back(s);
    }

    std::vector<std::vector<std::string>> res;
    for (auto& kv : m) res.push_back(kv.second);
    return res;
  }
};
