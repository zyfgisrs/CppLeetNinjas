struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//两两交换链表中的节点,递归实现
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    return swapPairs(head, head->next);
  }

  ListNode* swapPairs(ListNode* curr, ListNode* next) {
    //结束条件：只剩下最后两个节点
    if (next->next == nullptr) {
      next->next = curr;
      curr->next = nullptr;
      return next;
    }
    //结束条件：只剩下最后三个节点
    if (next->next->next == nullptr) {
      ListNode* temp = next->next;
      curr->next = temp;
      next->next = curr;
      return next;
    }

    //至少还有四个节点，进行递归交换
    ListNode* temp = next->next;
    next->next = curr;
    curr->next = swapPairs(temp, temp->next);
    return next;
  }
};