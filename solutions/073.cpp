// problem: https://neetcode.io/problems/search-for-word/question
// approach: backtracking w/ DFS to pare search space
// complexity: O(M*N*3^(L-1)) time, O(L) space, M := rows, N := cols, L := length word
#include <string>
#include <vector>

class Solution {
 private:
  bool search (std::vector<std::vector<char>>& board, const std::string& word,
               int i, int j, int k) {
    if (board[i][j] == '#' || word[k] != board[i][j]) return false;
    if (k == word.size() - 1) return true;
    // mark visited
    const char c = board[i][j];
    board[i][j] = '#';

    // dfs
    bool ok = (i > 0 && search(board, word, i - 1, j, k + 1)) ||
              (j > 0 && search(board, word, i, j - 1, k + 1)) ||
              (i < board.size() - 1 && search(board, word, i + 1, j, k + 1)) ||
              (j < board[0].size() - 1 && search(board, word, i, j + 1, k + 1));

    // unvisit
    board[i][j] = c;
    return ok;
  }

 public:
  bool exist (std::vector<std::vector<char>>& board, const std::string& word) {
    if (board.empty() || board[0].empty() || word.empty()) return false;
    const int M = board.size();
    const int N = board[0].size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (search(board, word, i, j, 0)) return true;
      }
    }
    return false;
  }
};
