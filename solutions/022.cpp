// problem: https://neetcode.io/problems/minimum-stack/question
// approach v2: maintain smallest with two vectors
// complexity: O(1) time, O(N) space, N := max num elements in stack
#include <algorithm>
#include <set>
#include <vector>

class MinStack {
 private:
  std::vector<int> M;
  std::vector<int> S;

 public:
  MinStack () = default;

  void push (int val) {
    S.push_back(val);
    M.push_back(M.empty() ? val : std::min(val, M.back()));
  }

  void pop () {
    M.pop_back();
    S.pop_back();
  }

  int top () const {
    return S.back();
  }

  int getMin () const {
    return M.back();
  }
};

// approach v1: maintain order with multiset
// complexity: O(log N) time, O(N) space, N := max num elements in stack
class SlowMinStack {
 private:
  std::vector<int> stk;
  std::multiset<int> s;

 public:
  SlowMinStack () = default;

  void push (int val) {
    stk.push_back(val);
    s.insert(val);
  }

  void pop () {
    int val = stk.back();
    stk.pop_back();
    s.erase(s.find(val));
  }

  int top () const {
    return stk.back();
  }

  int getMin () const {
    return *s.begin();
  }
};
