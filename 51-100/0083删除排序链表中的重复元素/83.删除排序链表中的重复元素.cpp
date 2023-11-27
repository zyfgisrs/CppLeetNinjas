
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
    if (!head) return head;  // 处理空链表的情况

    ListNode* current = head;
    while (current->next) {
      if (current->val == current->next->val) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;  // 删除重复的节点
      } else {
        current = current->next;
      }
    }
    return head;
  }
};