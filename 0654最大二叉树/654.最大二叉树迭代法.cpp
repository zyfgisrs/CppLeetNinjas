/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <vector>
// @lc code=start
#include <stack>
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
  TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    std::stack<TreeNode*> stack;
    for (int num : nums) {
      TreeNode* node = new TreeNode(num);
      while (!stack.empty() && stack.top()->val < num) {
        node->left = stack.top();
        stack.pop();
      }
      if (!stack.empty()) {
        stack.top()->right = node;
      }
      stack.push(node);
    }
    TreeNode* root = nullptr;
    while (!stack.empty()) {
      root = stack.top();
      stack.pop();
    }
    return root;
  }
};
// @lc code=end
