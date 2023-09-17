struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//反转列表的递归实现
class Solution {
 public:
  ListNode* reverseList(ListNode* head) { return reverseList(nullptr, head); }

  ListNode* reverseList(ListNode* prev, ListNode* current) {
    if (!current) {
      return prev;
    }

    ListNode* next = current->next;
    current->next = prev;
    return reverseList(current, next);
  }
};