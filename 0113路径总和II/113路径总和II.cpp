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
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(root, targetSum, result, path);
    return result;
  }

  void dfs(TreeNode *node, int targetSum, std::vector<std::vector<int>> &result,
           std::vector<int> &path) {
    path.push_back(node->val);

    if (targetSum == node->val && node->left == nullptr &&
        node->right == nullptr) {
      result.push_back(path);
    } else {
      dfs(node->left, targetSum - node->val, result, path);
      dfs(node->right, targetSum - node->val, result, path);
    }

    path.pop_back();
  }
};