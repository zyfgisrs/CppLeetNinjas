/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

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
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> result;
    if (root == nullptr) {
      return result;
    }
    std::string currStr;
    searchBinaryTreePaths(root, result, currStr);
    return result;
  }

  void searchBinaryTreePaths(TreeNode *node, std::vector<std::string> &res,
                             std::string &str) {
    if (!node) return;
    int len = str.length();
    str += (str.empty() ? "" : "->") + std::to_string(node->val);

    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(str);
    } else {
      searchBinaryTreePaths(node->left, res, str);
      searchBinaryTreePaths(node->right, res, str);
    }

    str.erase(len);
  }
};
// @lc code=end
