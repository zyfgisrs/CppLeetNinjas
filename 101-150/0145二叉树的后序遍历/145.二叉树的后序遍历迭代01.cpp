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
    while (!stack.empty()) {
      TreeNode *curr = stack.top();
      stack.pop();
      result.push_back(curr->val);
      if (curr->left) stack.push(curr->left);
      if (curr->right) stack.push(curr->right);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
