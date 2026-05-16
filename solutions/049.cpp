// problem: https://neetcode.io/problems/same-binary-tree/question
// approach: recursively compare curr val and childrens
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
  bool isSameTree (TreeNode* p, TreeNode* q) {
    if (!p || !q) return p == q;
    if (p->val != q->val)  return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
