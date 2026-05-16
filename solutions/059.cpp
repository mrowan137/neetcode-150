// problem: https://neetcode.io/problems/serialize-and-deserialize-binary-tree/question
// approach: encode tree in preorder format explicitly with markers, then decode
// complexity: O(N) time, O(N) space, N := num nodes
#include <sstream>
#include <string>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode () : val(0), left(nullptr), right(nullptr) {}
  TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode (int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
 public:
  // encode tree to a single string
  std::string serialize (TreeNode* root) {
    if (!root) return "#";
    return std::to_string(root->val) + " " + serialize(root->left) + " " +  serialize(root->right);
  }

  // decode encoded data to tree
  TreeNode* deserialize (const std::string& data) {
    std::istringstream ss(data);
    return parse(ss);
  }

  TreeNode* parse (std::istringstream& ss) {
    std::string token;
    ss >> token;
    if (token == "#") return nullptr;
    TreeNode* me = new TreeNode(std::stoi(token));
    me->left = parse(ss);
    me->right = parse(ss);
    return me;
  }
};
