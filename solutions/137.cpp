// problem: https://neetcode.io/problems/spiral-matrix/question
// approach: write a mapping from (i,j) --> linear index
// complexity: O(M*N) time, O(min(M, N)) space, M := rows, N := cols
#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder (const std::vector<std::vector<int>>& matrix) {
    const int M = matrix.size();
    const int N = matrix[0].size();
    auto idx = [&] (const int i, const int j, std::unordered_map<int, std::size_t>& offset_cache) {
      const int layer = std::min({i, j, M - 1 - i, N - 1 - j});

      // add cells from the traversed layers
      std::size_t cells = 0;
      std::size_t offset = 0;
      if (offset_cache.count(layer) != 0) {
        offset = offset_cache[layer];
      } else {
        for (int k = 0; k < layer; ++k) {
          int w = N - 2*k, l = M - 2*k;
          offset += 2*w + 2*l - 4;
        }
        offset_cache[layer] = offset;
      }
      cells += offset;

      // add cells from current layer
      int w = N - 2*layer, l = M - 2*layer;
      if      (i == layer && j < N - layer - 1)           cells += (j - layer);
      else if (j == (N - layer - 1) && i < M - layer - 1) cells += w + (i - layer) - 1;
      else if (i == (M - layer - 1) && j > layer)         cells += w + l + (N - 1 - layer - j) - 2;
      else if (j == layer && i < M - layer)               cells += w + l + w + (M - 1 - layer - i) - 3;

      return cells;
    };

    std::vector<int> res(M*N, 0);
    std::unordered_map<int, std::size_t> offset_cache;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        res[idx(i, j, offset_cache)] = matrix[i][j];
      }
    }

    return res;
  }
};
