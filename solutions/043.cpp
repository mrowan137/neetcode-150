// problem: https://neetcode.io/problems/merge-k-sorted-linked-lists/question
// approach: divide & conquer
// complexity: O(T log N) time, O(log N) space, T := total nodes, N := num lists
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  ListNode* merge (ListNode* x, ListNode* y) {
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;
    while (x && y) {
      if (x->val < y->val) {
        tmp->next = x;
        x = x->next;
      } else {
        tmp->next = y;
        y = y->next;
      }
      tmp = tmp->next;
    }
    if (x) tmp->next = x;
    if (y) tmp->next = y;
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
  }
  ListNode* helper (int i, int j, const std::vector<ListNode*>& lists) {
    // merge the lists in [i, j] inclusive
    if (i == j) return lists[i];
    if (i == j - 1) return merge(lists[i], lists[j]);
    int mid = (i + j)/2;
    ListNode* l = helper(i, mid, lists);
    ListNode* r = helper(mid + 1, j, lists);
    return merge(l, r);
  }

 public:
  ListNode* mergeKLists (const std::vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return helper(0, lists.size() - 1, lists);
  }
};
