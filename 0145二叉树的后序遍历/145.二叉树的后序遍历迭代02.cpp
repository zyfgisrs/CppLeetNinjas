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
    if (!root) {
      return result;
    }
    std::stack<TreeNode *> stack;

    TreeNode *curr = root;
    TreeNode *prev = nullptr;

    while (curr || !stack.empty()) {
      if (curr) {
        stack.push(curr);
        curr = curr->left;
      } else {
        TreeNode *topNode = stack.top();
        if (topNode->right != nullptr && prev != topNode->right) {
          curr = topNode->right;
          while (curr) {
            stack.push(curr);
            curr = curr->left;
          }
        } else {
          result.push_back(topNode->val);
          prev = stack.top();
          stack.pop();
        }
      }
    }
    return result;
  }
};
// @lc code=end
