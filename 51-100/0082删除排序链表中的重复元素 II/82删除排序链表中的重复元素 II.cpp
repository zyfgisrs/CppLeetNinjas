
//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    // prev指针负责指向有效的指针
    ListNode* prev = dummy;
    // head指针检查元素是否重复
    while (head) {
      if (head->next && head->val == head->next->val) {
        while (head->next && head->val == head->next->val) {
          head = head->next;
        }
        prev->next = head->next;
      } else {
        prev = head;
      }

      head = head->next;
    }

    return dummy->next;
  }
};