// problem: https://neetcode.io/problems/task-scheduling/question
// approach: count char(s) with max frequency, and arrange in groups
// complexity: O(N) time, O(1) space, N := array size
#include <algorithm>
#include <vector>

class Solution {
 public:
  int leastInterval (const std::vector<char>& tasks, int n) {
    // find the most frequent, max_freq
    // x__x__x__x  -- (max_freq - 1)*(n + 1) + 1
    // if there's multiple of max_freq, place one after another
    // xy_xy_xy_xy -- (max_freq - 1)*(n + 1) + cnt
    // if there's enough to fill the gaps, it's just the size of tasks
    // wxyzwxyzwxyzwxyz
    int letters[26] = {};
    for (char t : tasks) ++letters[t - 'A'];
    int max_freq = *std::max_element(std::begin(letters), std::end(letters));
    int cnt = std::count(std::begin(letters), std::end(letters), max_freq);
    return std::max((max_freq - 1)*(n + 1) + cnt, static_cast<int>(tasks.size()));
  }
};
