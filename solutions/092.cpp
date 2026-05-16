// problem: https://neetcode.io/problems/word-ladder/question
// approach: graph from word to conversion and BFS to target
// complexity: O(M*N^2) time, O(M*N^2) space, M := length beginWord, N := num words
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
 private:
  bool differ_by_one (const std::string& w1, const std::string& w2) {
    if (w1.size() != w2.size()) return false;
    int cnt = 0;
    for (int i = 0; i < w1.size(); ++i) {
      if (w1[i] != w2[i]) ++cnt;
      if (cnt > 1) return false;
    }
    return true;
  }

 public:
  int ladderLength (const std::string& beginWord, const std::string& endWord, std::vector<std::string>& wordList) {
    wordList.push_back(beginWord);
    std::unordered_map<std::string , std::vector<std::string>> graph;
    for (const auto& w1 : wordList) {
      for (const auto& w2 : wordList) {
        if (differ_by_one(w1, w2) && w2 != w1) graph[w1].push_back(w2);
      }
    }

    std::queue<std::pair<std::string, int>> q({{beginWord, 1}});
    std::unordered_set<std::string> seen;
    while (!q.empty()) {
      std::string w = q.front().first;
      int d = q.front().second;
      q.pop();
      if (w == endWord) return d;
      if (seen.count(w) != 0) continue;
      seen.insert(w);
      for (const auto& nbr : graph[w]) {
        q.push({nbr, d + 1});
      }
    }
    return 0;
  }
};
