// problem: https://neetcode.io/problems/lru-cache/question
// approach: doubly linked list + hashmap
// complexity: O(1) time, O(N) space, N := LRU cache capacity
#include <unordered_map>

class LRUCache {
  struct node {
    node* next = nullptr;
    node* prev = nullptr;
    int key = -1;
    int val = -1;
    node (int k, int v) : key(k), val(v) {}
  };

 private:
  node* dummy_head = nullptr;
  node* dummy_tail = nullptr;
  std::unordered_map<int, node*> m;
  int c = 0;
  int s = 0;

 public:
  LRUCache (int capacity) : c(capacity), s(0) {
    dummy_head = new node(-1, -1);
    dummy_tail = new node(-1, -1);
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
  }

  ~LRUCache () {
    node* tmp = dummy_head->next;
    while (tmp) {
      node* nxt = tmp->next;
      delete tmp;
      tmp = nxt;
    }
    // dummy_tail deleted in loop above
    delete dummy_head;
  }

  void update (int key) {
    node* n = m[key]->next;  // disconnect
    node* p = m[key]->prev;
    p->next = n; n->prev = p;

    node* rest = dummy_head->next;  // put to start of dll
    dummy_head->next = m[key];
    m[key]->prev = dummy_head;
    m[key]->next = rest;
    rest->prev = m[key];
  }

  int get (int key) {
    if (m.find(key) == m.end()) return -1;
    update(key);
    return m[key]->val;
  }

  void put (int key, int value) {
    if (m.find(key) != m.end()) {  // if it's there:
      // update map, update dll
      m[key]->val = value;
      update(key);
    } else {  // if not there:
      // update map, add at front
      node* add = new node(key, value);
      m[key] = add;
      node* rest = dummy_head->next;
      dummy_head->next = add;
      add->prev = dummy_head;
      add->next = rest;
      rest->prev = add;

      ++s;  // increment size

      if (s > c) {  // evict if at capacity (from list and map)
        node* remove = dummy_tail->prev;
        node* p = remove->prev;
        p->next = dummy_tail;
        dummy_tail->prev = p;
        m.erase(remove->key);
        delete remove;
        --s;
      }
    }
  }
};
