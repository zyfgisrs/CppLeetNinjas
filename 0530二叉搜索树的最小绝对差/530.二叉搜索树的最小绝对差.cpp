/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
#include <limits.h>

#include <stack>

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

// 使用中序遍历来遍历二叉搜索树，得到的结果是一个递增的序列
// 记录下前一个节点的值，然后和当前节点的值做差，与当前最小值进行比较，更新最小值
class Solution {
 public:
  int getMinimumDifference(TreeNode *root) {
    int min_diff = INT_MAX;
    TreeNode *prev = nullptr;
    TreeNode *curr = root;
    std::stack<TreeNode *> stack;
    while (!stack.empty() || curr) {
      while (curr) {
        stack.push(curr);
        curr = curr->left;
      }

      curr = stack.top();
      if (prev) min_diff = std::min(curr->val - prev->val, min_diff);
      stack.pop();
      prev = curr;
      curr = curr->right;
    }
    return min_diff;
  }
};
// @lc code=end
