/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <stack>
#include <vector>
// @lc code=start

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution
{
public:
  std::vector<int> inorderTraversal(TreeNode *root)
  {
    std::vector<int> result;
    std::stack<TreeNode *> stack;

    if (!root)
      return result;
    TreeNode *curr = root;
    while (curr || !stack.empty())
    {
      if (curr)
      {
        stack.push(curr);
        curr = curr->left;
      }
      else
      {
        TreeNode *topNode = stack.top();
        stack.pop();
        result.push_back(topNode->val);
        if (topNode->right)
          curr = topNode->right;
      }
    }
    return result;
  }
};
// @lc code=end
