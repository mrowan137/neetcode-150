// problem: https://neetcode.io/problems/linked-list-cycle-detection/question
// approach: push slow and fast ptrs, found a cycle when they match
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
  bool hasCycle (ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};
