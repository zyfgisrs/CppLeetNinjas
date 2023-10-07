/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root);

    std::unordered_set<TreeNode*> ancestors;

    while (p) {
      ancestors.insert(p);
      p = node_to_parent_map[p];
    }

    while (q) {
      if (ancestors.count(q)) {
        return q;
      }

      q = node_to_parent_map[q];
    }

    return nullptr;
  }

 private:
  std::unordered_map<TreeNode*, TreeNode*> node_to_parent_map;

  void dfs(TreeNode* root) {
    if (root->left) {
      node_to_parent_map[root->left] = root;
      dfs(root->left);
    }

    if (root->right) {
      node_to_parent_map[root->right] = root;
      dfs(root->right);
    }
  }
};
// @lc code=end
