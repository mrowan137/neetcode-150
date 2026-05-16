// problem: https://neetcode.io/problems/car-fleet/question
// approach: stack, count increasing times then num fleets is size of stack
// complexity: O(N log N) time, O(N) space, N := array size
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

class Solution {
 public:
  int carFleet (int target, const std::vector<int>& position, const std::vector<int>& speed) {
    // sort by position, compute times; iterate from back and store times in the stack
    // if time is larger than top of stack, it's a different fleet;
    // if less than, it means the car behind catches up, thus part of the same fleet;
    // so we just count the times that are increasing, and the number of fleets will be size of the stack
    std::stack<float> s;
    const int n = static_cast<int>(speed.size());
    std::vector<std::pair<int, int>> ps;
    for (int i = 0; i < n; ++i) {
      ps.push_back({position[i], speed[i]});
    }
    auto comp = [](const auto& x, const auto& y) { return x.first < y.first; };
    std::sort(ps.begin(), ps.end(), comp);

    for (int i = n - 1; i >= 0; --i) {
      float t = (target - ps[i].first)/static_cast<float>(ps[i].second);
      if (s.empty() || s.top() < t) {
        s.push(t);
      }
    }
    return static_cast<int>(s.size());
  }
};
