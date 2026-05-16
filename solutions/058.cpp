// problem: https://neetcode.io/problems/binary-tree-maximum-path-sum/question
// approach: DFS the tree, calculate max path sum each step and pass up path
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height
#include <algorithm>
#include <climits>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode () : val(0), left(nullptr), right(nullptr) {}
  TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode (int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int ret = INT_MIN;
  int mps (TreeNode* root) {
    if (!root) return 0;
    int l = mps(root->left);
    int r = mps(root->right);
    int me = root->val;
    ret = std::max({l + me, r + me, l + r + me, me, ret});
    return std::max({l + me, r + me, me, 0});
  }

 public:
  int maxPathSum (TreeNode* root) {
    // at each node, measure the max path sum
    // pass up either l + me, r + me, me, or 0 if it's dumpster fire
    ret = INT_MIN;
    mps(root);
    return ret;
  }
};
