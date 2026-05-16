// problem: https://neetcode.io/problems/copy-linked-list-with-random-pointer/question
// approach: make a map from addr(orig) -> idx(orig), apply to copy to set random ptrs
// complexity: O(N) time, O(N) space, N := list length
#include <cstddef>
#include <unordered_map>
#include <vector>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node (int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 private:
  std::unordered_map<Node*, int> m;

 public:
  Node* copyRandomList (Node* head) {
    Node* o = head;
    Node* d = new Node(-1);
    Node* c = d;
    int idx = 0;
    std::vector<Node*> copy;
    while (o) {
      // build the new list
      c->next = new Node(o->val);

      // store (addr,idx) pairs
      m[o] = idx++;

      c = c->next;
      copy.push_back(c);
      o = o->next;
    }

    // record the mapping
    std::vector<int> r;
    o = head;
    idx = 0;
    while (o) {
      r.push_back(o->random ? m[o->random] : -1);
      o = o->next;
    }

    // apply the new mapping
    for (int i = 0; i < copy.size(); ++i) {
      copy[i]->random = r[i] != -1 ? copy[r[i]] : nullptr;
    }

    Node* ret = d->next;
    delete d;
    return ret;
  }
};
