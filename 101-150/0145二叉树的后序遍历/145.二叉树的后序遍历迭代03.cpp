/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>

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
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result;
    if (root == nullptr) {
      return result;
    }

    std::stack<TreeNode *> stack;
    stack.push(root);
    stack.push(root);

    while (!stack.empty()) {
      TreeNode *node = stack.top();
      stack.pop();
      if (!stack.empty() && stack.top() == node) {
        // 如果右子节点存在，将其推入栈两次
        if (node->right != nullptr) {
          stack.push(node->right);
          stack.push(node->right);
        }
        // 如果左子节点存在，将其推入栈两次
        if (node->left != nullptr) {
          stack.push(node->left);
          stack.push(node->left);
        }
      } else {
        // 访问节点
        result.push_back(node->val);
      }
    }

    return result;
  }
};

// @lc code=end
