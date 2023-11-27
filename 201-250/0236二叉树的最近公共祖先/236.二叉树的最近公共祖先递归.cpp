/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 函数的目的是找到二叉树中两个给定节点的最近公共祖先
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 如果当前节点为空或者当前节点就是目标节点之一，直接返回当前节点
    if (!root || root == p || root == q) {
      return root;
    }

    // 递归调用左子树，查找 p 和 q 在左子树中的最近公共祖先
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    // 递归调用右子树，查找 p 和 q 在右子树中的最近公共祖先
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // 如果 p 和 q
    // 分别在当前节点的左右子树中，那么当前节点就是它们的最近公共祖先
    if (left && right) {
      return root;
    }

    // 否则，如果 p 和 q 都在左子树或都在右子树，返回左子树或右子树的结果
    return left ? left : right;
  }
};

// @lc code=end
