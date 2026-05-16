// problem: https://neetcode.io/problems/top-k-elements-in-list/question
// approach v2: note freqs are bounded [0, N] and count from back
// complexity: O(N) time, O(N) space, N := array size
#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent (const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (int n : nums) ++count[n];

    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (const auto& [num, freq] : count) buckets[freq].push_back(num);

    std::vector<int> res;
    for (int i = nums.size(); i >= 0 && res.size() < static_cast<std::size_t>(k); --i) {
      for (int n : buckets[i]) {
        res.push_back(n);
        if (res.size() == static_cast<std::size_t>(k)) return res;
      }
    }
    return res;
  }
};

// approach v1: tally and sort elements by frequency
// complexity: O(N log N) time, O(N) space, N := array size
class SlowSolution {
 public:
  std::vector<int> topKFrequent (const std::vector<int>& nums, int k) {
    // record num --> count in unordered map
    std::unordered_map<int, std::size_t> count;
    for (int n : nums) ++count[n];

    // move to sortable container
    std::vector<std::pair<int, std::size_t>> num_freq;
    for (const auto& kv : count) num_freq.push_back({kv.first, kv.second});

    // sort by count
    std::sort(num_freq.begin(), num_freq.end(),
              [](const auto& kv1, const auto& kv2) {
                return kv1.second > kv2.second;
              });

    // return top k
    std::vector<int> res;
    for (int i = 0; i < k; ++i) res.push_back(num_freq[i].first);
    return res;
  }
};
