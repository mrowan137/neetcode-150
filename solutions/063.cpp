// problem: https://neetcode.io/problems/kth-largest-element-in-an-array/question
// approach: use min heap or max heap depending which end is closer to target
// complexity: O(N log N) time, O(min(K, N - K)) space, N := array size, K := rank of kth largest
#include <queue>
#include <vector>

class Solution {
  struct comp_max {
    bool operator() (const int& x, const int& y) const {
      return x < y;
    }
  };
  struct comp_min {
    bool operator() (const int& x, const int& y) const {
      return x > y;
    }
  };

 public:
  int findKthLargest (const std::vector<int>& nums, int k) {
    // we can remove the k - 1 largest from max heap
    // or we can remove N - k smallest from min heap
    // do whichever one make sense
    if (k > nums.size()/2) {
      std::priority_queue<int, std::vector<int>, comp_max> pq;
      for (int n : nums) {
        pq.push(n);
        if (pq.size() > nums.size() - (k - 1)) pq.pop();
      }
      return pq.top();
    } else {
      std::priority_queue<int, std::vector<int>, comp_min> pq;
      for (int n : nums) {
        pq.push(n);
        if (pq.size() > k ) pq.pop();
      }
      return pq.top();
    }
  }
};
