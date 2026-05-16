// problem: https://neetcode.io/problems/clone-graph/question
// approach: DFS; use map to mark clones
// complexity: O(V + E) time, O(V) space, V := num vertices, E := num edges
#include <unordered_map>
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node () {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node (int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node (int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 private:
  std::unordered_map<Node*, Node*> cloned;

 public:
  Node* cloneGraph (Node* node) {
    if (!node || cloned[node]) return cloned[node];
    cloned[node] = new Node(node->val);
    for (auto nbr : node->neighbors) {
      cloned[node]->neighbors.push_back(cloneGraph(nbr));
    }
    return cloned[node];
  }
};
