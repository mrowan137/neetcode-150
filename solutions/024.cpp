// problem: https://neetcode.io/problems/daily-temperatures/question
// approach: stack, resolve temperature when we find an increase
// complexity: O(N) time, O(N) space, N := array size
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> dailyTemperatures (const std::vector<int>& temperatures) {
    // goal: for each day, number of days to warmer day
    // invariant: stack T is always decreasing
    // then when we find an increase, we can fill in
    // those days that are less than the current
    std::vector<int> ret(temperatures.size(), 0);
    std::stack<int> s;
    for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
      while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
        ret[s.top()] = i - s.top(); s.pop();
      }
      s.push(i);
    }
    return ret;
  }
};
