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
    std::stack<TreeNode *> nodes_stack;

    while (root || !nodes_stack.empty()) {
      while (root) {
        nodes_stack.push(root);
        root = root->left;
      }

      root = nodes_stack.top();
      nodes_stack.pop();
      result.push_back(root->val);

      root = root->right;
    }

    return result;
  }
};

// @lc code=end
