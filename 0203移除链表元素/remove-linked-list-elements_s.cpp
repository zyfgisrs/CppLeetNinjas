struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//不使用虚拟节点
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
      ListNode* toDeleteNode = head;
      head = head->next;
      delete toDeleteNode;
    }
    if (head == nullptr) return head;
    ListNode* curr = head;
    while (curr->next) {
      if (curr->next->val == val) {
        ListNode* toDeleteNode = curr->next;
        curr->next = curr->next->next;
        delete toDeleteNode;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
