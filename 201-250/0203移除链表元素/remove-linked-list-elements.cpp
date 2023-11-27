struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//使用虚拟节点
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
      if (curr->val == val) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};
