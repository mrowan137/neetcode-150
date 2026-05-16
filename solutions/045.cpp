// problem: https://neetcode.io/problems/invert-a-binary-tree/question
// approach: recursively invert child nodes
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height

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
  TreeNode* invertTree (TreeNode* root) {
    if (!root) return root;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};
