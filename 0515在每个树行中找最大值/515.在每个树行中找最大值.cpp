/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start

//  Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

// #include <limits>
// #include <queue>
// #include <vector>

class Solution {
 public:
  std::vector<int> largestValues(TreeNode *root) {
    std::vector<int> result;
    std::queue<TreeNode *> nodeQueue;
    if (root == nullptr) return result;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      int max = std::numeric_limits<int>::min();
      for (int i = 0; i < count; i++) {
        TreeNode *topNode = nodeQueue.front();
        if (topNode->left) nodeQueue.push(topNode->left);
        if (topNode->right) nodeQueue.push(topNode->right);
        max = std::max(max, topNode->val);
        nodeQueue.pop();
      }
      result.push_back(max);
    }
    return result;
  }
};
// @lc code=end
