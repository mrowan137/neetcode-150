// problem: https://neetcode.io/problems/kth-largest-integer-in-a-stream/question
// approach: maintain min heap size k, anything added can only displace current kth largest
// complexity: O(M log K) time, O(K) space, M := num times add is called, K := heap size
#include <queue>
#include <vector>

class KthLargest {
  struct comp {
    bool operator() (const int& x, const int& y) const {
      return x > y;
    }
  };

 private:
  int k_ = 0;
  std::priority_queue<int, std::vector<int>, comp> pq;
 public:
  KthLargest (int k, const std::vector<int>& nums) :  k_(k) {
    for (int n : nums) pq.push(n);
    while (pq.size() > k_) pq.pop();
  }

  int add (int val) {
    pq.push(val);
    if (pq.size() > k_) pq.pop();
    return pq.top();
  }
};
