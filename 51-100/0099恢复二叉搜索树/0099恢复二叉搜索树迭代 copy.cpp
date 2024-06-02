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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;
    std::stack<TreeNode *> st;

    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      root = st.top();
      st.pop();
      if (prev != nullptr) {
        if (prev->val > root->val) {
          if (first == nullptr) {
            first = prev;
            second = root;
          } else {
            second = root;
          }
        }
      }
      prev = root;
      root = root->right;
    }
    std::swap(first, second);
  }
};