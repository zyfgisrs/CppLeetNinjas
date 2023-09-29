/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
#include <algorithm>
//   Definition for a binary tree node.
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
  bool isBalanced(TreeNode *root) { return checkBalance(root) != -1; }

  int checkBalance(TreeNode *node) {
    if (!node) return 0;

    int leftHeight = checkBalance(node->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkBalance(node->right);
    if (rightHeight == -1) return -1;

    if (std::abs(leftHeight - rightHeight) > 1) return -1;

    return std::max(leftHeight, rightHeight) + 1;
  }
};
// @lc code=end
