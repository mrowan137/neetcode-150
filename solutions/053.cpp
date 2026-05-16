// problem: https://neetcode.io/problems/binary-tree-right-side-view/question
// approach: BFS, record nodes as seen from right
// complexity: O(N) time, O(N) space, N := num nodes
#include <queue>
#include <utility>
#include <vector>

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
  std::vector<int> rightSideView (TreeNode* root) {
    std::vector<int> ret;
    std::queue<std::pair<TreeNode*, int>> q({{root, 0}});
    while (!q.empty() && q.front().first) {
      auto [n, d] = q.front(); q.pop();
      if (d >= ret.size()) ret.push_back(n->val);
      if (n->right) q.push({n->right, d + 1});
      if (n->left) q.push({n->left, d + 1});
    }
    return ret;
  }
};
