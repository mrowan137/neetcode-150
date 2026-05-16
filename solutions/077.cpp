// problem: https://neetcode.io/problems/implement-prefix-tree/question
// approach: encode letters positionally as pointer to trie, with flag marking end
// complexity: O(N) time, O(T) space, N := length word, T := total nodes in trie
#include <string>

class PrefixTree {
 struct trie {
   trie* nxt[26]{};
   bool is_terminal = false;
   ~trie () {
     for (int i = 0; i < 26; ++i) delete nxt[i];
   }
 };

 private:
  trie* t;

 public:
  PrefixTree () : t(new trie) {}

  void insert (const std::string& word) {
    // add it to the trie
    trie* curr = t;
    for (char c : word) {
      if (!curr->nxt[c - 'a']) {
        curr->nxt[c - 'a'] = new trie;
      }
      curr = curr->nxt[c - 'a'];
    }
    curr->is_terminal = true;  // mark end of a word
  }

  bool search (const std::string& word) const {
    // find letters in trie, see if it's terminal
    trie* curr = t;
    for (char c : word) {
      if (!curr->nxt[c - 'a']) return false;
      curr = curr->nxt[c - 'a'];
    }
    return curr->is_terminal;
  }

  bool startsWith (const std::string& prefix) const {
    trie* curr = t;
    for (char c : prefix) {
      if (!curr->nxt[c - 'a']) return false;
      curr = curr->nxt[c - 'a'];
    }
    return true;
  }
};
