/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else {
      if (!root->left && !root->right) {
        delete root;
        return nullptr;
      }

      if (!root->left) {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }

      if (!root->right) {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }

      // 后继节点
      TreeNode *minNode = getMin(root->right);
      root->val = minNode->val;
      // 删除后继节点
      root->right = deleteNode(root->right, minNode->val);
      return root;
    }
    return root;
  }

 private:
  TreeNode *getMin(TreeNode *root) {
    while (root->left) {
      root = root->left;
    }
    return root;
  }
};
// @lc code=end
