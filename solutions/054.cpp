// problem: https://neetcode.io/problems/count-good-nodes-in-binary-tree/question
// approach v2: BFS
// complexity: O(N) time, O(N) space, N := num nodes
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode () : val(0), left(nullptr), right(nullptr) {}
  TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode (int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int goodNodes (TreeNode* root) {
    // good: x.val > n.val for all n in path r-to-x
    // let's track the max seen to each path
    // the node is good if it val is gtr than max so far
    std::queue<std::pair<TreeNode*, int>> q({{root, INT_MIN}});
    int ret = 0;
    while (!q.empty() && q.front().first) {
      auto [n, max_so_far] = q.front(); q.pop();
      if (n->val >= max_so_far) ++ret;
      if (n->left) q.push({n->left, std::max(n->val, max_so_far)});
      if (n->right) q.push({n->right, std::max(n->val, max_so_far)});
    }
    return ret;
  }
};

// approach v1: DFS
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height
class AltSolution {
 private:
  int ret = 0;
  void dfs (TreeNode* n, int max_so_far) {
    if (!n) return;
    if (n->val >= max_so_far) ++ret;
    if (n->left) dfs(n->left, std::max(n->val, max_so_far));
    if (n->right) dfs(n->right, std::max(n->val, max_so_far));
  }

 public:
  int goodNodes (TreeNode* root) {
    ret = 0;
    dfs(root, INT_MIN);
    return ret;
  }
};
