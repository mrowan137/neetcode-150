// problem: https://neetcode.io/problems/search-for-word-ii/question
// approach: encode dictionary in trie and explore only words in the dictionary
// complexity: O(M*N*3**(T - 1)) time, O(S) space, M := rows, N := cols,
//             T := max word length, S := sum of lengths of all words
#include <string>
#include <vector>

class Solution {
  struct trie {
    trie* nxt[26]{};
    std::string w = "";
    ~trie () {
      for (int i = 0; i < 26; ++i) delete nxt[i];
    }
  };

 private:
  void search (int i, int j, std::vector<std::vector<char>>& board, trie* curr,
               std::vector<std::string>& res) {
    // exit condition -- seen the square or mismatch letter
    if (board[i][j] == '#' || !curr) return;

    // matching word -- but continue search in case this a prefix
    curr = curr->nxt[board[i][j] - 'a'];
    if (curr && !curr->w.empty()) {
      res.push_back(curr->w);
      curr->w = "";  // avoid repeat
    }

    char c = board[i][j];
    board[i][j] = '#';
    if (i > 0) search (i - 1, j, board, curr, res);
    if (j > 0) search (i, j - 1, board, curr, res);
    if (i < board.size() - 1) search (i + 1, j, board, curr, res);
    if (j < board[0].size() - 1) search (i, j + 1, board, curr, res);
    board[i][j] = c;
  }

 public:
  std::vector<std::string> findWords (std::vector<std::vector<char>>& board,
                                      const std::vector<std::string>& words) {
    const int M = board.size();
    const int N = board[0].size();
    std::vector<std::string> res;
    trie* dict = new trie;

    // fill dictionary
    for (std::string s : words) {
      trie* curr = dict;
      for (char c : s) {
        if (!curr->nxt[c - 'a']) {
          curr->nxt[c - 'a'] = new trie;
        }
        curr = curr->nxt[c - 'a'];
      }
      curr->w = s;
    }

    // search for words
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        search(i, j, board, dict, res);
      }
    }

    // cleanup
    delete dict;
    return res;
  }
};
