// problem: https://neetcode.io/problems/design-twitter-feed/question
// approach: record users' tweets, construct 10 most recent with min heap
// complexity: O(N log N) time, O(N + F) space, N := num tweets, F := num follow relationships
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Twitter {
  using tweet_t = std::pair<int, int>;  // tweet ID, time
  struct comp {
    bool operator() (const tweet_t& x, const tweet_t& y) const {
      return x.second > y.second;  // tweets in min heapcompare by time; oldest first
    }
  };

 private:
  std::unordered_map<int, std::unordered_set<int>> following;
  std::unordered_map<int, std::vector<tweet_t>> tweets;
  int t = 0;

 public:
  Twitter () {}

  void postTweet (int userId, int tweetId) {
    tweets[userId].push_back({tweetId, t++});
  }

  std::vector<int> getNewsFeed (int userId) const {
    std::priority_queue<tweet_t, std::vector<tweet_t>, comp> pq;
    auto it_t = tweets.find(userId);
    if (it_t != tweets.end()) {
      for (const tweet_t& t : it_t->second) pq.push(t);
    }

    auto it_f = following.find(userId);
    if (it_f != following.end()) {
      for (const auto& f : it_f->second) {
        if (f == userId) continue;
        auto it_tf = tweets.find(f);
        if (it_tf == tweets.end()) continue;
        for (const tweet_t& t : it_tf->second) pq.push(t);
      }
    }

    while (pq.size() > 10) pq.pop();
    std::vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top().first);
      pq.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }

  void follow (int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  void unfollow (int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }
};
