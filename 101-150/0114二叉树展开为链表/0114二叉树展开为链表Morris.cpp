#include <stack>

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
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        // 寻找左子树最右侧的节点
        TreeNode *predecessor = curr->left;
        while (predecessor->right) {
          predecessor = predecessor->right;
        }

        // 将当前节点的右子树接到左子树的最右侧节点
        predecessor->right = curr->right;

        // 将左子树作为右子树
        curr->right = curr->left;
        curr->left = nullptr;
      }

      // 移到右子树
      curr = curr->right;
    }
  }
};
