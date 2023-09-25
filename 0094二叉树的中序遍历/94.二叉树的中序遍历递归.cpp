/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <stack>
#include <vector>
// @lc code=start

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
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result;
    inorderTraversal(root, result);
    return result;
  }

  void inorderTraversal(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) {
      return;
    }
    if (node->left) inorderTraversal(node->left);
    result.push_back(node->val);
    if (node->right) inorderTraversal(node->right);
  }
};
// @lc code=end
