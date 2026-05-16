// problem: https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree/question
// approach: use BST ordering; descend as far as you can while p,q are on the same side; stop at split
// complexity: O(H) time, O(1) space, H := tree height

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
  TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val) return lowestCommonAncestor(root, q, p);  // enforce p < q
    while (root) {
      TreeNode* l = root->left;
      TreeNode* r = root->right;
      if (root->val > q->val) root = l;
      else if (root->val < p->val) root = r;
      else return root;
    }
    return nullptr;  // shouldn't get here
  }
};
