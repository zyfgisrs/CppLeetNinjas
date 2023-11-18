
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* dummyBigger = new ListNode(0);
    ListNode* dummySmaller = new ListNode(0);

    ListNode* bigger = dummyBigger;
    ListNode* smaller = dummySmaller;

    while (head) {
      if (head->val < x) {
        smaller->next = head;
        smaller = head;
      } else {
        bigger->next = head;
        bigger = head;
      }
      head = head->next;
    }

    smaller->next = dummyBigger->next;
    bigger->next = nullptr;

    return dummySmaller->next;
  }
};