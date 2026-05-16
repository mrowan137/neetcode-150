// problem: https://neetcode.io/problems/foreign-dictionary/question
// approach: pairwise words to create in-degree and graph --> topological sort
// complexity: O(N + V + E) time, O(V + E) space, N := sum of string lengths,
//             V := num unique characters (vertices), E := num edges
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string foreignDictionary (const std::vector<std::string>& words) {
    std::unordered_map<char, std::vector<char>> g;
    std::unordered_map<char, int> ind;
    for (int i = 0; i < words.size(); ++i) {
      for (char c : words[i]) ind[c] = 0;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
      std::string w1 = words[i], w2 = words[i + 1];
      int ml = std::min(w1.size(), w2.size());
      for (int j = 0; j < ml; ++j) {
        if (w1[j] != w2[j]) {
          ++ind[w2[j]];
          g[w1[j]].push_back(w2[j]);
          goto nxt;
        }
      }
      if (w1.size() > w2.size()) return "";
    nxt:;
    }
    std::string res = "";
    std::queue<char> q;
    for (auto [c, d] : ind) if (d == 0) q.push(c);
    while (!q.empty()) {
      char c = q.front(); q.pop();
      res += c;
      for (char x : g[c]) {
        if (--ind[x] == 0) q.push(x);
      }
    }
    return res.size() == ind.size() ? res : "";
  }
};
