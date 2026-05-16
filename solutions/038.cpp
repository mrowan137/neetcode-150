// problem: https://neetcode.io/problems/remove-node-from-end-of-linked-list/question
// approach v2: fast & slow pointers to signal nth from end
// complexity: O(N) time, O(1) space, N := list length

struct ListNode {
  int val;
  ListNode* next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd (ListNode* head, int n) {
    ListNode* f = head;
    ListNode* s = head;
    ListNode* d = new ListNode();
    d->next = head;
    for (int i = 0; i < n; ++i) f = f->next;
    ListNode* prev = d;
    while (f) {
      prev = prev->next;
      s = s->next;
      f = f->next;
    }
    prev->next = s->next;
    s->next = nullptr;
    ListNode* ret = d->next;
    delete d;
    return ret;
  }
};

// approach v1: recursion w/ count to measure nth from end
// complexity: O(N) time, O(N) space, N := list length
class SlowSolution {
 private:
  int from_end (ListNode* node) {
    if (!node) return 0;
    return 1 + from_end(node->next);
  }

 public:
  ListNode* removeNthFromEnd (ListNode* head, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* tmp = head;
    int count = from_end(tmp);
    for (int i = 0; i < count - n; ++i) {
      prev = tmp;
      tmp = tmp->next;
    }
    prev->next = (tmp ? tmp->next : nullptr);
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
  }
};
