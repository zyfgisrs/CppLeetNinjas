/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start

//   Definition for a binary tree node.
#include <algorithm>
#include <queue>
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
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int currLevel = nodeQueue.size();
      std::vector<int> currLevelNode;
      for (int i = 0; i < currLevel; i++) {
        TreeNode *topNode = nodeQueue.front();
        if (topNode->left) nodeQueue.push(topNode->left);
        if (topNode->right) nodeQueue.push(topNode->right);
        currLevelNode.push_back(topNode->val);
        nodeQueue.pop();
      }
      result.push_back(currLevelNode);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
