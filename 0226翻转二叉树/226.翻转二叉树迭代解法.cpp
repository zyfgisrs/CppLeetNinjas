/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
#include <queue>
//  Definition for a binary tree node.
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
  TreeNode *invertTree(TreeNode *root) {
    std::queue<TreeNode *> q;
    if (root == nullptr) {
      return nullptr;
    }
    q.push(root);
    while (!q.empty()) {
      TreeNode *topNode = q.front();
      TreeNode *temp = topNode->left;
      topNode->left = topNode->right;
      topNode->right = temp;

      if (topNode->left) q.push(topNode->left);
      if (topNode->right) q.push(topNode->right);
      q.pop();
    }
    return root;
  }
};
// @lc code=end
