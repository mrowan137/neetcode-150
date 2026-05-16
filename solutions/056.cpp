// problem: https://neetcode.io/problems/kth-smallest-integer-in-bst/question
// approach: DFS, count to kth
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
 private:
  int count = 0;
  int ret = -1;
  void dfs (TreeNode* root, int k) {
    if (!root) return;
    dfs(root->left, k);
    ++count;
    if (count == k) {
      ret = root->val;
      return;
    }
    dfs(root->right, k);
  }

 public:
  int kthSmallest (TreeNode* root, int k) {
    ret = -1;
    dfs(root, k);
    return ret;
  }
};
