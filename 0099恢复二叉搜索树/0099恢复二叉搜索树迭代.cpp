#include <stack>

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
  void recoverTree(TreeNode *root) {
    std::stack<TreeNode *> st;
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;

    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      root = st.top();
      st.pop();
      if (prev && prev->val > root->val) {
        if (!first) first = prev;
        second = root;
      }

      prev = root;
      root = root->right;
    }

    int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }
};