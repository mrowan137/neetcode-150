// problem: https://neetcode.io/problems/find-median-in-a-data-stream/question
// approach: use min heap and max heap to maintain the median element
// complexity: O(log N) time, O(N) space, N := num elements
#include <queue>
#include <vector>

class MedianFinder {
  struct comp_min {
    bool operator() (const int& x, const int& y) const {
      return x > y;
    }
  };
  struct comp_max {
    bool operator() (const int& x, const int& y) const {
      return x < y;
    }
  };

 private:
  std::priority_queue<int, std::vector<int>, comp_max> pql;
  std::priority_queue<int, std::vector<int>, comp_min> pqr;

 public:
  MedianFinder () {}

  void addNum (int num) {
    pql.push(num);
    // maintain ordering
    if (!pqr.empty() && pql.top() > pqr.top()) {
      pqr.push(pql.top());
      pql.pop();
    }
    // maintain size
    while (pqr.size() < pql.size() - 1) {
      pqr.push(pql.top());
      pql.pop();
    }
    while (pql.size() < pqr.size()) {
      pql.push(pqr.top());
      pqr.pop();
    }
  }

  double findMedian () const {
    if (pql.size() == pqr.size()) {
      return 0.5*(static_cast<double>(pqr.top()) + static_cast<double>(pql.top()));
    } else {
      return pql.top();
    }
  }
};
