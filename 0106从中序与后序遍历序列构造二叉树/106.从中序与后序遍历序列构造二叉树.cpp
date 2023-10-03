/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <vector>
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
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) {
      return nullptr;
    }
    int n = postorder.size();
    int rootValue = postorder[n - 1];
    int i = 0;
    for (; i < n; i++) {
      if (inorder[i] == rootValue) break;
    }
    TreeNode *root = new TreeNode(rootValue);
    std::vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
    std::vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
    std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + i);
    std::vector<int> rightPostorder(postorder.begin() + i, postorder.end() - 1);
    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);
    return root;
  }
};
// @lc code=end
