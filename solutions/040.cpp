// problem: https://neetcode.io/problems/add-two-numbers/question
// approach: rote addition procedure, track the carry
// complexity: O(max(M, N)) time, O(1) space, M := list length l1, N := list length l2

struct ListNode {
  int val;
  ListNode* next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;
    int carry = 0;
    while (l1 || l2) {
      int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = s/10;
      s %= 10;
      tmp->next = new ListNode(s);
      tmp = tmp->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    // deal w/ carry
    if (carry) tmp->next = new ListNode(1);

    return dummy->next;
  }
};
