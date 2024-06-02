
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
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }

 private:
  int dfs(TreeNode *curr, int num) {
    if (curr == nullptr) {
      return 0;
    }
    int currentSum = num * 10 + curr->val;

    if (!curr->left && !curr->right) {
      return currentSum;
    }

    return dfs(curr->left, currentSum) + dfs(curr->right, currentSum);
  }
};