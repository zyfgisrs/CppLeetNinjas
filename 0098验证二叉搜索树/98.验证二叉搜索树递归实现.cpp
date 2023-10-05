/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start

//   Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode* left, TreeNode* right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, nullptr, nullptr);
  }

 private:
  bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
    // Base case: an empty tree is a valid BST
    if (node == nullptr) {
      return true;
    }

    // Ensure that the current node's value is within the range (minNode->val,
    // maxNode->val)
    if (minNode != nullptr && node->val <= minNode->val) {
      return false;
    }
    if (maxNode != nullptr && node->val >= maxNode->val) {
      return false;
    }

    // Check the left subtree with updated maxNode and the right subtree with
    // updated minNode
    return isValidBSTHelper(node->left, minNode, node) &&
           isValidBSTHelper(node->right, node, maxNode);
  }
};
// @lc code=end
