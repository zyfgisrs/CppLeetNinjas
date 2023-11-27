/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode* leftNode = root, *rightNode = root;
        
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // 2^h - 1
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
// @lc code=end

