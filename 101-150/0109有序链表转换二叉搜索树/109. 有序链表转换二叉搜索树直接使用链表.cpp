#include <vector>
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) { return buildBST(head, nullptr); }

 private:
  TreeNode* buildBST(ListNode* start, ListNode* end) {
    if (start == end) return nullptr;

    ListNode* slow = start;
    ListNode* fast = start;
    // 找到中间节点，slow将成为中间节点
    while (fast != end && fast->next != end) {
      slow = slow->next;
      fast = fast->next->next;
    }

    TreeNode* node = new TreeNode(slow->val);
    node->left = buildBST(start, slow);
    node->right = buildBST(slow->next, end);

    return node;
  }
};