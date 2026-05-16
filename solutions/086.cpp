// problem: https://neetcode.io/problems/surrounded-regions/question
// approach: DFS; flood-fill edge land, change interior land to water, and revert edge
// complexity: O(M*N) time, O(M*N) space, M := rows, N := cols
#include <string>
#include <vector>

class Solution {
 private:
  void flood (int i, int j, std::vector<std::vector<char>>& board) {
    const int M = board.size();
    const int N = board[0].size();

    // no seen
    if (std::string("CX").find(board[i][j]) != std::string::npos) return;
    board[i][j] = 'C';

    // search
    if (i > 0     && board[i - 1][j] == 'O') flood(i - 1, j, board);
    if (j > 0     && board[i][j - 1] == 'O') flood(i, j - 1, board);
    if (i < M - 1 && board[i + 1][j] == 'O') flood(i + 1, j, board);
    if (j < N - 1 && board[i][j + 1] == 'O') flood(i, j + 1, board);
  }

 public:
  void solve (std::vector<std::vector<char>>& board) {
    // if edge is water, find any interior land and floodfill
    const int M = board.size();
    const int N = board[0].size();

    // flood fill land connected to edge
    int i = 0;
    for (int j = 0; j < N; ++j) {
      if (board[i][j] == 'O') flood(i, j, board);
    }

    i = M - 1;
    for (int j = 0; j < N; ++j) {
      if (board[i][j] == 'O') flood(i, j, board);
    }
    int j = 0;
    for (int i = 0; i < M; ++i) {
      if (board[i][j] == 'O') flood(i, j, board);
    }

    j = N - 1;
    for (int i = 0; i < M; ++i) {
      if (board[i][j] == 'O') flood(i, j, board);
    }

    // invert interior land
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
      }
    }

    // revert boundary land
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == 'C') board[i][j] = 'O';
      }
    }
  }
};
