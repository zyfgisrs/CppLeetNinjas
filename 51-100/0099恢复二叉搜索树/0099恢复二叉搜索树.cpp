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
  TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

  void recoverTree(TreeNode *root) {
    inorder(root);
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }

 private:
  void inorder(TreeNode *node) {
    if (!node) return;
    inorder(node->left);

    if (prev && prev->val > node->val) {
      if (!first) first = prev;
      second = node;
    }
    prev = node;

    inorder(node->right);
  }
};