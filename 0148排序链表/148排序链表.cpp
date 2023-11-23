
//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = nullptr;
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);

    ListNode* ans = merge(l1, l2);
    return ans;
  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);

    ListNode* tail = dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy->next;
  }
};