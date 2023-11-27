/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
#include <stack>

//  Definition for a binary tree node.
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
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) return 0;
    int sum = 0;
    std::stack<TreeNode *> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode *topNode = stack.top();
      stack.pop();
      if (!stack.empty() && stack.top() == nullptr) {
        stack.pop();
        if (topNode->left == nullptr && topNode->right == nullptr) {
          sum += topNode->val;
        }
      }

      if (topNode->left) {
        stack.push(nullptr);
        stack.push(topNode->left);
      }

      if (topNode->right) {
        stack.push(topNode->right);
      }
    }
    return sum;
  }
};
// @lc code=end
