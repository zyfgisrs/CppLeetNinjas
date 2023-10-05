/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
#include <limits.h>

#include <stack>
#include <vector>

//   Definition for a binary tree node.
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
  bool isValidBST(TreeNode* root) {
    std::stack<TreeNode*> stack;
    long long prevVal = static_cast<long long>(INT_MIN) - 1;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }

      root = stack.top();

      stack.pop();

      if (root->val <= prevVal) return false;  // check inorder property

      prevVal = root->val;  // update previous inorder value

      root = root->right;  // move to right subtree
    }

    return true;
  }
};
// @lc code=end
