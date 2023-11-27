/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <unordered_map>
#include <vector>

// @lc code=start

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  std::unordered_map<int, int> value_to_index_map;

  TreeNode* buildTreeRecursive(std::vector<int>& preorder, int preStart,
                               int preEnd, std::vector<int>& inorder,
                               int inStart, int inEnd) {
    if (preStart > preEnd) {
      return nullptr;
    }
    int rootValue = preorder[preStart];             // 根节点的值
    int rootIndex = value_to_index_map[rootValue];  // 根节点在中序的位置
    int len = rootIndex - inStart;  // 根节点距离与inStart距离
    TreeNode* root = new TreeNode(rootValue);

    root->left = buildTreeRecursive(preorder, preStart + 1, preStart + len,
                                    inorder, inStart, inStart + len - 1);
    root->right = buildTreeRecursive(preorder, preStart + len + 1, preEnd,
                                     inorder, inStart + len + 1, inEnd);

    return root;
  }

 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      value_to_index_map[inorder[i]] = i;
    }
    return buildTreeRecursive(preorder, 0, preorder.size() - 1, inorder, 0,
                              inorder.size() - 1);
  }
};
// @lc code=end
