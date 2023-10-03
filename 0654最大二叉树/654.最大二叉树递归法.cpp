/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <vector>
// @lc code=start

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
  TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    return constructMaximumBinaryTreeRecursive(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *constructMaximumBinaryTreeRecursive(std::vector<int> &nums,
                                                int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int max = nums[start];
    int index = start;
    for (int i = start; i <= end; i++) {
      if (nums[i] > max) {
        index = i;
        max = nums[i];
      }
    }
    TreeNode *root = new TreeNode(max);
    root->left = constructMaximumBinaryTreeRecursive(nums, start, index - 1);
    root->right = constructMaximumBinaryTreeRecursive(nums, index + 1, end);
    return root;
  }
};
// @lc code=end
