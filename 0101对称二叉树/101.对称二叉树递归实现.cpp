/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
#include <queue>
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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return compare(root->left, root->right);
  }

  bool compare(TreeNode *left, TreeNode *right) {
    if ((left == nullptr && right != nullptr) ||
        (left != nullptr && right == nullptr)) {
      return false;
    } else if (left == nullptr && right == nullptr) {
      return true;
    } else if (left->val != right->val) {
      return false;
    }
    bool outer = compare(left->left, right->right);
    bool inner = compare(left->right, right->left);
    return outer && inner;
  }
};
// @lc code=end
