
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    for (int i = 0; i < left - 1; i++) {
      if (prev->next) prev = prev->next;
    }

    ListNode* curr = prev->next;
    ListNode* next = nullptr;

    for (int i = 0; i < right - left; i++) {
      next = curr->next;
      curr->next = curr->next->next;
      next->next = curr;

      prev->next = next;
    }

    return dummy->next;
  }
};