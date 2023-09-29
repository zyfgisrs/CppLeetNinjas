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
    if (!root) return result;
    std::stack<TreeNode *> st;
    std::unordered_map<TreeNode *, std::string> node_to_string_map;
    st.push(root);
    node_to_string_map[root] = std::to_string(root->val);
    while (!st.empty()) {
      TreeNode *topNode = st.top();
      st.pop();
      if (topNode->right) {
        st.push(topNode->right);
        node_to_string_map[topNode->right] =
            node_to_string_map[topNode] + "->" +
            std::to_string(topNode->right->val);
      }
      if (topNode->left) {
        st.push(topNode->left);
        node_to_string_map[topNode->left] = node_to_string_map[topNode] + "->" +
                                            std::to_string(topNode->left->val);
      }
      if (topNode->left == nullptr && topNode->right == nullptr) {
        result.push_back(node_to_string_map[topNode]);
      }
    }
    return result;
  }
};
// @lc code=end
