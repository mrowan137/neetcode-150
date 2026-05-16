// problem: https://neetcode.io/problems/valid-binary-search-tree/question
// approach: track bounds through min,max to verify BST ordering
// complexity: O(N) time, O(H) space, N := num nodes, H := tree height
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
  bool dfs (TreeNode* root, long low, long high) {  // longs keeps e.g. {1, INT_MIN} a valid tree
    // base case: nullptr is a valid bst
    if (!root) return true;

    // check the bounds are satisfied
    if (root->val <= low || root->val >= high) return false;

    // descend the childs
    return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
  }

 public:
  bool isValidBST (TreeNode* root) {
    // invariant: my val is gt everything in left tree
    //                      lt everything in right tree
    // each node has a bounds that's controlled by the path that got there
    // we update these bounds with each edge we descend in the tree
    return dfs(root, LONG_MIN, LONG_MAX);
  }
};
