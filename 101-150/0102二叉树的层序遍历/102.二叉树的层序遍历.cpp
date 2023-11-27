/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;
    std::queue<TreeNode *> nodeQueue;
    if (root == nullptr) return result;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      std::vector<int> currLevelNode;
      int currLevel = nodeQueue.size();
      for (int i = 0; i < currLevel; i++) {
        TreeNode *topNode = nodeQueue.front();
        if (topNode->left) nodeQueue.push(topNode->left);
        if (topNode->right) nodeQueue.push(topNode->right);
        currLevelNode.push_back(topNode->val);
        nodeQueue.pop();
      }
      result.push_back(currLevelNode);
    }
    return result;
  }
};
// @lc code=end
