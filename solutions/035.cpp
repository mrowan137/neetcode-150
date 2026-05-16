// problem: https://neetcode.io/problems/merge-two-sorted-linked-lists/question
// approach: sequentially add node w/ lesser value, then remainder
// complexity: O(M + N) time, O(1) space, M := list length list1, N := list length list2

struct ListNode {
  int val;
  ListNode* next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    curr->next = (list1 ? list1 : list2);
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
  }
};
