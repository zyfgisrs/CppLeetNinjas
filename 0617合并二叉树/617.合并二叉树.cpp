/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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

class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    return helper(root1, root2);
  }

  TreeNode *helper(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return nullptr;
    }

    TreeNode *node = new TreeNode();
    if (!root2) {
      node->val = root1->val;
      node->left = helper(root1->left, nullptr);
      node->right = helper(root1->right, nullptr);
    } else if (!root1) {
      node->val = root2->val;
      node->left = helper(nullptr, root2->left);
      node->right = helper(nullptr, root2->right);
    } else {
      node->val = root1->val + root2->val;
      node->left = helper(root1->left, root2->left);
      node->right = helper(root1->right, root2->right);
    }

    return node;
  }
};
// @lc code=end
