// problem: https://neetcode.io/problems/reverse-a-linked-list/question
// approach: track prev,curr and stitch nodes in reverse order
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
  ListNode* reverseList (ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* prev = nullptr;
    ListNode* curr  = head;
    while (curr) {
      ListNode* nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }
};
