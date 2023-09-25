/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
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
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result;
    preorderTraversal(root, result);
    return result;
  }

  void preorderTraversal(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) {
      return;
    }
    result.push_back(node->val);
    preorderTraversal(node->left, result);
    preorderTraversal(node->right, result);
  }
};
// @lc code=end
