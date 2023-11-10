
//  * Definition for a binary tree node.
#include <algorithm>
#include <limits>
#include <stack>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 中遍遍历（从大到小进行遍历）
class Solution {
 public:
  int closestValue(TreeNode *root, double target) {
    int result = root->val;
    double min_diff = std::numeric_limits<double>::max();
    std::stack<TreeNode *> st;

    while (!st.empty() || root) {
      while (root) {
        st.push(root);
        root = root->right;
      }

      root = st.top();
      st.pop();
      double diff = std::abs(root->val - target);
      if (diff <= min_diff) {
        result = root->val;
        min_diff = diff;
      }
      root = root->left;
    }

    return result;
  }
};