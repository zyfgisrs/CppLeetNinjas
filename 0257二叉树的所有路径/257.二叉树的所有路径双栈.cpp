/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

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
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> result;
    std::stack<TreeNode *> nodeStack;
    std::stack<std::string> strStack;
    if (!root) return result;
    nodeStack.push(root);
    strStack.push(std::to_string(root->val));
    while (!nodeStack.empty()) {
      TreeNode *top = nodeStack.top();
      nodeStack.pop();
      std::string topStr = strStack.top();
      strStack.pop();
      if (top->left == nullptr && top->right == nullptr) {
        result.push_back(topStr);
      }

      if (top->left) {
        nodeStack.push(top->left);
        strStack.push(topStr + "->" + std::to_string(top->left->val));
      }

      if (top->right) {
        nodeStack.push(top->right);
        strStack.push(topStr + "->" + std::to_string(top->right->val));
      }
    }
    return result;
  }
};
// @lc code=end
