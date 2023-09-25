/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
#include <algorithm>
#include <queue>
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
  int minDepth(TreeNode *root) {
    std::queue<TreeNode *> nodeQueue;
    if (root == nullptr) return 0;
    nodeQueue.push(root);
    int result = 0;
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      result++;
      for (int i = 0; i < count; i++) {
        TreeNode *topNode = nodeQueue.front();
        if (topNode->right) {
          nodeQueue.push(topNode->right);
        }
        if (topNode->left) {
          nodeQueue.push(topNode->left);
        }
        if (topNode->left == nullptr && topNode->right == nullptr) {
          return result;
        }
        nodeQueue.pop();
      }
    }
    return result;
  }
};
// @lc code=end
