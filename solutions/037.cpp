// problem: https://neetcode.io/problems/reorder-linked-list/question
// approach: split first & second halves, reverse second, merge
// complexity: O(N) time, O(1) space, N := list length

struct ListNode {
  int val;
  ListNode* next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  ListNode* reverse (ListNode* x) {
    ListNode* dummy = new ListNode();
    ListNode* curr = x;
    while (curr) {
      ListNode* tmp = dummy->next;
      ListNode* nxt = curr->next;
      dummy->next = curr;
      curr->next = tmp;
      curr = nxt;
    }

    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
  }

  void merge (ListNode* x, ListNode* y) {
    if (!x || !y) return;
    // splice together x and y, x come first
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    bool take_from_x = true;
    while (x && y) {
      if (take_from_x) {
        curr->next = x;
        x = x->next;
      } else {
        curr->next = y;
        y = y->next;
      }
      curr = curr->next;
      take_from_x = !take_from_x;
    }

    curr->next = (x ? x : y);
    delete dummy;
    return;
  }

 public:
  void reorderList (ListNode* head) {
    if (!head || !head->next) return;
    // 0 1 2 3 4 5 6
    // 0   1   2.  3 : first half of list
    //   6.  5.  4.  : second half of list in reverse
    // 1. get first and second half
    // 2. reverse the second half
    // 3. merge together

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* rsecond = reverse(second);  // reverse second half
    merge(head, rsecond);
  }
};
