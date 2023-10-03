/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
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
  int findBottomLeftValue(TreeNode *root) {
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int res;
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      res = nodeQueue.front()->val;
      for (int i = 0; i < count; i++) {
        TreeNode *front = nodeQueue.front();
        nodeQueue.pop();
        if (front->left) {
          nodeQueue.push(front->left);
        }

        if (front->right) {
          nodeQueue.push(front->right);
        }
      }
    }
    return res;
  }
};
// @lc code=end
