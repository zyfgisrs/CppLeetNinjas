/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start

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
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> result;
    std::queue<TreeNode *> nodeQueue;
    if (root == nullptr) return result;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      double sum = 0;
      for (int i = 0; i < count; i++) {
        TreeNode *topNode = nodeQueue.front();
        sum += topNode->val;
        if (topNode->left) nodeQueue.push(topNode->left);
        if (topNode->right) nodeQueue.push(topNode->right);
        nodeQueue.pop();
      }
      result.push_back(sum / count);
    }
    return result;
  }
};
// @lc code=end
