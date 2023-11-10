/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
#include <stack>
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
    std::stack<TreeNode *> stack;
    if (root != nullptr) {
      stack.push(root);
    }
    while (!stack.empty()) {
      TreeNode *pop = stack.top();
      stack.pop();
      result.push_back(pop->val);
      if (pop->right) stack.push(pop->right);

      if (pop->left) stack.push(pop->left);
    }
    return result;
  }
};
// @lc code=end
