/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
#include <stack>

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
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) return 0;
    int sum = 0;
    std::stack<TreeNode *> nodes;
    std::stack<bool> isLeftNodes;
    nodes.push(root);
    isLeftNodes.push(false);  // 根节点不是左叶子节点
    while (!nodes.empty()) {
      TreeNode *current = nodes.top();
      bool isLeft = isLeftNodes.top();
      nodes.pop();
      isLeftNodes.pop();
      if (current->left == nullptr && current->right == nullptr && isLeft) {
        sum += current->val;
      }

      if (current->left) {
        nodes.push(current->left);
        isLeftNodes.push(true);
      }
      if (current->right) {
        nodes.push(current->right);
        isLeftNodes.push(false);
      }
    }
    return sum;
  }
};
// @lc code=end
