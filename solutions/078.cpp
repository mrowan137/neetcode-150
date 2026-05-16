// problem: https://neetcode.io/problems/design-word-search-data-structure/question
// approach: encode dictionary in trie
// complexity: addWord O(N) & search O(26^N) time, O(T) space,
//             N := length word, T := total nodes in trie
#include <string>

class WordDictionary {
  struct trie {
    trie* nxt[26]{};
    bool terminal = false;
    ~trie () {
      for (auto& t : nxt) delete t;
    }
  };

 private:
  trie* t = nullptr;

  bool helper (trie* curr, int i, const std::string& word) const {
    // exit conditions
    if (!curr) return false;
    if (i == word.size()) return curr->terminal;

    // char is a--z or '.'
    if (word[i] != '.') {
      curr = curr->nxt[word[i] - 'a'];
      return helper(curr, i + 1, word);
    } else {
      bool res = false;
      for (int j = 0; j < 26; ++j) {
        res |= helper(curr->nxt[j], i + 1, word);
      }
      return res;
    }
  }

 public:
  WordDictionary () : t(new trie) {}

  void addWord (const std::string& word) {
    trie* curr = t;
    for (char c : word) {
      if (!curr->nxt[c - 'a']) {
        curr->nxt[c - 'a'] = new trie;
      }
      curr = curr->nxt[c - 'a'];
    }
    curr->terminal = true;
  }

  bool search (const std::string& word) const {
    return helper(t, 0, word);
  }
};
