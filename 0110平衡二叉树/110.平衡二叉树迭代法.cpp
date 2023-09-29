/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <unordered_map>
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
  using HeightType = int;

 public:
  bool isBalanced(TreeNode *root) {
    if (!root) return true;

    struct Element {
      TreeNode *node;
      int leftHeight;
      int rightHeight;
      int state;  // 0初始；1左结点已处理；2右节点已处理
    };

    std::stack<Element> stack;
    std::unordered_map<TreeNode *, HeightType> node_to_height_map;
    stack.push({root, 0, 0, 0});
    while (!stack.empty()) {
      Element &top = stack.top();
      TreeNode *topNode = stack.top().node;
      if (!topNode) {
        stack.pop();
        continue;
      }
      if (top.state == 0) {
        stack.push({topNode->left, 0, 0, 0});
        top.state = 1;
      } else if (top.state == 1) {
        top.leftHeight = topNode->left ? node_to_height_map[topNode->left] : 0;
        stack.push({topNode->right, 0, 0, 0});
        top.state = 2;
      } else {
        top.rightHeight =
            topNode->right ? node_to_height_map[topNode->right] : 0;
        if (std::abs(top.leftHeight - top.rightHeight) > 1) return false;
        node_to_height_map[topNode] =
            std::max(top.leftHeight, top.rightHeight) + 1;
        stack.pop();
      }
    }
    return true;
  }
};
// @lc code=end
