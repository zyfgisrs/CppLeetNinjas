/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <limits>
  // Definition for a binary tree node.
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
  int minDepth(TreeNode *root) {
    if (!root) return 0; //数为空，深度为0
    if(root->left == nullptr && root -> right == nullptr)return 1; //是叶子节点
  
    //不是叶子结点
    int leftminDepth = INT_MAX;
    if (root->left != nullptr) leftminDepth = minDepth(root->left);
    
    int rightminDepth = INT_MAX;
    if (root->right != nullptr) rightminDepth = minDepth(root->right);
    
    return std::min(leftminDepth, rightminDepth) + 1;
  }
};
// @lc code=end
