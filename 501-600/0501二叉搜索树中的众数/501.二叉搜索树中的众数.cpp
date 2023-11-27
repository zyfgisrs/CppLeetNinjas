/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
#include <limits.h>

#include <stack>
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

// 单调栈
// 中序遍历
class Solution {
 public:
  std::vector<int> findMode(TreeNode *root) {
    std::stack<TreeNode *> stack;
    std::vector<int> vec;
    int prev = INT_MIN;
    int count = 0;
    int maxCount = 0;
    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }

      root = stack.top();
      stack.pop();
      if (root->val == prev) {
        count++;
      } else {
        count = 1;
        prev = root->val;
      }

      if (count > maxCount) {
        vec = {root->val};
        maxCount = count;
      } else if (count == maxCount) {
        vec.push_back(root->val);
      }

      // 转向右子树
      root = root->right;
    }
    return vec;
  }
};
// @lc code=end
