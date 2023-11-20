
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    while (!(p1->next == nullptr && p2->next == nullptr)) {
      if (p1->next == nullptr) {
        p1->next = new ListNode(0);
      }
      if (p2->next == nullptr) {
        p2->next = new ListNode(0);
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    p1 = l1;
    p2 = l2;
    ListNode* last = nullptr;
    int num = 0;

    while (p1 != nullptr && p2 != nullptr) {
      int sum = p1->val + p2->val + num;
      num = sum / 10;
      p1->val = sum % 10;
      last = p1;
      p1 = p1->next;
      p2 = p2->next;
    }

    if (num != 0) {
      last->next = new ListNode(num);
    }
    return l1;
  }
};