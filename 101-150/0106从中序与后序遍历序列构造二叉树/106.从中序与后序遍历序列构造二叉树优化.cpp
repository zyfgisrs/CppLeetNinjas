/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <unordered_map>
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
  private : using RootValue = int;
  using RootIndex = int;
  std::unordered_map<RootValue, RootIndex> value_to_index_map;

  TreeNode *buildTreeRecursive(std::vector<int> &inorder, int inorderLeft,
                               int inorderRight, std::vector<int> &postorder,
                               int postorderLeft, int postorderRight) {
    if (inorderLeft > inorderRight) return nullptr;
    int rootValue = postorder[postorderRight];

    int rootIndex = value_to_index_map[rootValue];
    TreeNode *root = new TreeNode(rootValue);
    int lenLeft = rootIndex - inorderLeft;

    root->left =
        buildTreeRecursive(inorder, inorderLeft, rootIndex - 1, postorder,
                           postorderLeft, postorderLeft + lenLeft - 1);
    root->right =
        buildTreeRecursive(inorder, rootIndex + 1, inorderRight, postorder,
                           postorderLeft + lenLeft, postorderRight - 1);

    return root;
  }

 public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
      value_to_index_map[inorder[i]] = i;
    }

    return buildTreeRecursive(inorder, 0, n - 1, postorder, 0, n - 1);
  }
};
// @lc code=end
