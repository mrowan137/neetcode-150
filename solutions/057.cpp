// problem: https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal/question
// approach v2: track right and left subtrees with indices, build recursively
// complexity: O(N) time, O(N) space, N := num nodes
#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <vector>

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
  TreeNode* build (std::size_t pl, std::size_t pr, const std::vector<int>& preorder,
                   std::size_t il, std::size_t ir, const std::vector<int>& inorder,
                   std::unordered_map<int, std::size_t>& mp) {
    if (pl > pr) return nullptr;

    int rt = preorder[pl];
    TreeNode* root = new TreeNode(rt);

    // inorder:  [il, ..., split - 1][split][split + 1, ..., ir]
    // preorder: [pl][pl + 1, ..., pl + split - il][pl + split - il + 1, ..., pr]
    std::size_t split = mp[rt];

    // left subtree
    std::size_t il_next = il;
    std::size_t ir_next = split - 1;
    std::size_t pl_next = pl + 1;
    std::size_t pr_next = pl + split - il;
    root->left = build(pl_next, pr_next, preorder,
                       il_next, ir_next, inorder,
                       mp);
    // right subtree
    il_next = split + 1;
    ir_next = ir;
    pl_next = pl + 1 + (split - il);
    pr_next = pr;
    root->right = build(pl_next, pr_next, preorder,
                        il_next, ir_next, inorder,
                        mp);

    return root;
  }

 public:
  TreeNode* buildTree (const std::vector<int>& preorder, const std::vector<int>& inorder) {
    std::unordered_map<int, std::size_t> mp;
    for (std::size_t i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
    return build(0, preorder.size() - 1, preorder,
                 0, inorder.size() - 1, inorder,
                 mp);
  }
};

// approach v1: locate root using preorder, use to split inorder, then take from preorder
// complexity: O(N^2) time, O(N^2) space, N := num nodes
class SlowSolution {
 public:
  TreeNode* buildTree (const std::vector<int>& preorder, const std::vector<int>& inorder) {
    // preorder: me, L, R
    // inorder:  L, me, R
    if (preorder.empty()) return nullptr;

    int rt = preorder[0];
    TreeNode* root = new TreeNode(rt);

    // get root from preorder[0]
    // this divide inorder into two halves, L and R
    // length of these tell us how preorder breaks up
    auto inorder_root  = std::find(inorder.begin(), inorder.end(), rt);
    std::vector<int> inorder_l(inorder.begin(), inorder_root);
    std::vector<int> inorder_r(inorder_root + 1, inorder.end());
    std::vector<int> preorder_l(preorder.begin() + 1,
                                preorder.begin() + 1 + inorder_l.size());
    std::vector<int> preorder_r(preorder.begin() + 1 + inorder_l.size(),
                                preorder.begin() + 1 + inorder_l.size() + inorder_r.size());


    root->left  = buildTree(preorder_l, inorder_l);
    root->right = buildTree(preorder_r, inorder_r);

    return root;
  }
};
