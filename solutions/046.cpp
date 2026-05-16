// problem: https://neetcode.io/problems/depth-of-binary-tree/question
// approach: current node pass up 1 + max(childs' max depths)
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height
#include <algorithm>

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
  int maxDepth (TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};
