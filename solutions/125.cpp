// problem: https://neetcode.io/problems/gas-station/question
// approach v2: Kadane; if the current prefix sum ever hurts, discard and start anew
// complexity: O(N) time, O(1) space, N := array size gas
#include <vector>

class Solution {
 public:
  int canCompleteCircuit (const std::vector<int>& gas, const std::vector<int>& cost) {
    const int N = gas.size();
    int start = 0, fuel = 0, check = 0;
    for (int i = 0; i < N; ++i) {
      // if current prefix ever hurts,
      // discard and start again
      if (fuel < 0) {
        start = i;
        fuel = 0;
      }
      fuel += (gas[i] - cost[i]);
      check += (gas[i] - cost[i]);
    }
    // sanity check: must be more gas than cost overall
    return check >= 0 ? start : -1;
  }
};

// approach v1: direct simulation
// complexity: O(2N) time, O(1) space, N := array size gas
class SlowSolution {
 public:
  int canCompleteCircuit (const std::vector<int>& gas, const std::vector<int>& cost) {
    const int N = gas.size();
    int start = 0, fuel = 0, dist = 0;
    for (int i = 0; i < (2*N - 1); ++i) {
      if (fuel < 0) {
        start = i%N;
        dist = 0;
        fuel = 0;
      }
      fuel += (gas[i%N] - cost[i%N]);
      dist += 1;
      if (dist == N && fuel >= 0) return start;
    }
    return -1;
  }
};
