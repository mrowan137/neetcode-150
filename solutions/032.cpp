// problem: https://neetcode.io/problems/time-based-key-value-store/question
// approach: binary search on the timestamp
// complexity: O(log N) time, O(T) space, N := num values for key, T := num key-value pairs
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
 private:
  // timestemp gives us an ordering
  // data = { k1 : { t1_v1, t2_v2},
  //          k2 : { .. }
  // }
  // so natural would be:
  //   unordered map<string, vector<pair<int, string>>>
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> buckets;

 public:
  TimeMap () = default;

  void set (const std::string& key, const std::string& value, int timestamp) {
    buckets[key].push_back({timestamp, value});
  }

  std::string get (const std::string& key, int timestamp) const {
    auto it = buckets.find(key);
    if (it == buckets.end()) return "";

    if (it->second.back().first <= timestamp) return it->second.back().second;

    const int n = static_cast<int>(it->second.size());
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r)/2;
      if (it->second[mid].first < timestamp) l = mid + 1;
      else if (it->second[mid].first > timestamp) r = mid - 1;
      else return it->second[mid].second;
    }
    return (r >= 0) ? it->second[r].second : "";
  }
};
