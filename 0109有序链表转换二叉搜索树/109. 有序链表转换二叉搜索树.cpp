#include <vector>
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    std::vector<int> vals;
    while (head) {
      vals.push_back(head->val);
      head = head->next;
    }
    return createTree(vals, 0, vals.size() - 1);
  }

  TreeNode *createTree(std::vector<int> &vals, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(vals[mid], nullptr, nullptr);
    node->left = createTree(vals, left, mid - 1);
    node->right = createTree(vals, mid + 1, right);
    return node;
  }
};