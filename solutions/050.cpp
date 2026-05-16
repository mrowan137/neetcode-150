// problem: https://neetcode.io/problems/subtree-of-a-binary-tree/question
// approach: check for tree in each node
// complexity: O(M*N) time, O(H) space, M := num nodes root,
//             N := num nodes subRoot, H := tree height

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
  bool same (TreeNode* x, TreeNode* y) {
    if (!x || ! y) return x == y;
    if (x->val != y->val) return false;
    return same(x->left, y->left) && same(x->right, y->right);
  }

 public:
  bool isSubtree (TreeNode* root, TreeNode* subRoot) {
    if (!root || ! subRoot) return root == subRoot;
    return same(root, subRoot)
           || isSubtree(root->left, subRoot)
           || isSubtree(root->right, subRoot);
  }
};
