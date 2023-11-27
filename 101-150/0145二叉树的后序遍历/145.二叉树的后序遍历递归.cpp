/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
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
  /**
   * @brief 递归后续遍历二叉树
   *
   * @param root 根节点
   * @return std::vector<int> 返回的结果数组
   */
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> vec;
    postorderTraversal(root, vec);
    return vec;
  }
  /**
   * @brief 递归函数
   *
   * @param node 检查的结点
   * @param result 存储结果的数组
   */
  void postorderTraversal(TreeNode *node, std::vector<int> &result) {
    if (node == nullptr) {
      return;
    }
    postorderTraversal(node->left, result);
    postorderTraversal(node->right, result);
    result.push_back(node->val);
  }
};
// @lc code=end
