struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//两两交换链表中的节点，迭代实现
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* result = head->next;
    ListNode* curr = head;
    ListNode* next = head->next;
    while (next != nullptr && next->next != nullptr &&
           next->next->next != nullptr) {
      ListNode* temp = next->next;
      curr->next = temp->next;
      next->next = curr;
      curr = temp;
      next = curr->next;
    }

    if (next->next != nullptr && next->next->next == nullptr) {
      ListNode* temp = next->next;
      next->next = curr;
      curr->next = temp;
    }

    if (next->next == nullptr) {
      next->next = curr;
      curr->next = nullptr;
    }
    return result;
  }
};