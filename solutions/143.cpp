// problem: https://neetcode.io/problems/count-squares/question
// approach: counter to track number of points at i,j;
//           track min, max i and scan, checking for squares if it's a hit
// complexity: add O(1) and count O(R) time, O(N) space, R := x-coordinate range, N := num unique points
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

class CountSquares {
 private:
  std::unordered_map<int, std::unordered_map<int, int>> points;
  int mini = INT_MAX, maxi = INT_MIN;

 public:
  void add (const std::vector<int>& point) {
    int i = point[0], j = point[1];
    points[i][j] += 1;
    maxi = std::max(maxi, i);
    mini = std::min(mini, i);
  }

  int get (int i, int j) const {
    auto it = points.find(i);
    if (it == points.end()) return 0;
    auto jt = it->second.find(j);
    return (jt != it->second.end()) ? jt->second : 0;
  }

  int count (const std::vector<int>& point) const {
    int res = 0;
    int i0 = point[0], j0 = point[1];
    for (int i = mini; i <= maxi; ++i) {
      if (i == i0) continue;
      auto it = points.find(i);
      if (it == points.end()) continue;
      if (it->second.count(j0) != 0) {  // if (points[i][j0]!=0)
        int side = i - i0;
        // the point can form a square above or below
        res += get(i, j0)*get(i0, j0 + side)*get(i, j0 + side);
        res += get(i, j0)*get(i0, j0 - side)*get(i, j0 - side);
      }
    }
    return res;
  }
};
