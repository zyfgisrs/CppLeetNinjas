#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

//  * Definition for a binary tree node.
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
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> result;
    std::queue<TreeNode *> queue;
    bool leftToRight = true;

    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();
      std::vector<int> level(size);
      for (int i = 0; i < size; ++i) {
        TreeNode *node = queue.front();
        queue.pop();
        level[i] = node->val;
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
      if (leftToRight) {
        result.push_back(level);
      } else {
        std::reverse(level.begin(), level.end());
        result.push_back(level);
      }
      leftToRight = !leftToRight;
    }
    return result;
  }
};