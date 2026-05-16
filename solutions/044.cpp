// problem: https://neetcode.io/problems/reverse-nodes-in-k-group/question
// approach: separate into k-groups, reverse, link back together
// complexity: O(N) time, O(N) space, N := num nodes
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
  ListNode* reverse (ListNode* x) {
    ListNode* d = new ListNode(-1);
    while (x) {
      ListNode* rest = d->next;
      ListNode* xn = x->next;
      d->next = x;
      x->next = rest;
      x = xn;
    }
    ListNode* ret = d->next;
    delete d;
    return ret;
  }

 public:
  ListNode* reverseKGroup (ListNode* head, int k) {
    // separate lists into groups of k
    std::vector<ListNode*> kgroups;
    std::vector<int> len;
    ListNode* tmp = head;
    while (tmp) {
      int l = 0;
      ListNode* h = tmp;
      ListNode* p;
      for (int i = 0; i < k && tmp; ++i) {
        p = tmp;
        tmp = tmp->next;
        ++l;
      }
      p->next = nullptr;
      kgroups.push_back(h);
      len.push_back(l);
    }

    // reverse
    for (int i = 0; i < kgroups.size(); ++i) {
      if (len[i] == k) {
        kgroups[i] = reverse(kgroups[i]);
      }
    }

    // link back together
    ListNode* d = new ListNode(-1);
    d->next = kgroups[0];
    for (int i = 0; i < kgroups.size() - 1; ++i) {
      ListNode* h = kgroups[i];
      ListNode* tmp = h;
      ListNode* p = nullptr;
      for (int j = 0; j < len[i]; ++j) {
        p = tmp;
        tmp = tmp->next;
      }
      p->next = kgroups[i + 1];
    }

    ListNode* ret = d->next;
    delete d;
    return ret;
  }
};
