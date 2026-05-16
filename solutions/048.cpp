// problem: https://neetcode.io/problems/balanced-binary-tree/question
// approach: compute max heights bottom-up, and pass 1) height, or 2) 'oh no!'
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height
#include <algorithm>
#include <cstdlib>

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
  int d (TreeNode* root) {
    if (!root) return 0;
    int l = d(root->left);

    if (l == -1) return -1;

    int r = d(root->right);
    if (r == -1) return -1;

    if (std::abs(l - r) > 1) return -1;
    return 1 + std::max(l, r);
  }

 public:
  bool isBalanced (TreeNode* root) {
    return d(root) == -1 ? false : true;
  }
};
