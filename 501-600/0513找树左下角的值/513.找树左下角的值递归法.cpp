/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
#include <queue>
//   Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    int result = root->val;
    int maxDepth = 0;
    dfs(root, 0, maxDepth, result);
    return result;
  }

 private:
  void dfs(TreeNode *node, int depth, int &maxDepth, int &num) {
    if (node == nullptr) return;

    if (depth > maxDepth) {
      num = node->val;
      maxDepth = depth;
    }

    dfs(node->left, depth + 1, maxDepth, num);
    dfs(node->right, depth + 1, maxDepth, num);
  }
};
// @lc code=end
