// problem: https://neetcode.io/problems/binary-tree-diameter/question
// approach: recursively check and update diameter
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
  int m = INT_MIN;
  int helper (TreeNode* root) {
    if (!root) return 0;
    int l = helper(root->left);
    int r = helper(root->right);
    m = std::max(m, l + r);
    return 1 + std::max(l, r);
  }

 public:
  int diameterOfBinaryTree (TreeNode* root) {
    m = INT_MIN;
    helper(root);
    return m;
  }
};
