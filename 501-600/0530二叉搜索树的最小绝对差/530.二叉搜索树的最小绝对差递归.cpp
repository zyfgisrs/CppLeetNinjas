/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
#include <limits.h>

#include <stack>

//   Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 private:
  int min_diff = INT_MAX;
  TreeNode *prev = nullptr;

 public:
  int getMinimumDifference(TreeNode *root) {
    getMinimumDifferenceHelper(root);
    return min_diff;
  }

  void getMinimumDifferenceHelper(TreeNode *node) {
    if (node == nullptr) return;
    getMinimumDifferenceHelper(node->left);

    if (prev) {
      min_diff = std::min(min_diff, node->val - prev->val);
    }
    prev = node;

    getMinimumDifferenceHelper(node->right);
  }
};
// @lc code=end
