/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
#include <queue>
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        std::queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();

            if (!t1 && !t2)
                continue; // Both nodes are nullptr, so they are symmetric
            if (!t1 || !t2)
                return false; // One of the nodes is nullptr, not symmetric
            if (t1->val != t2->val)
                return false; // Values are not equal, not symmetric

            // Push children in mirrored order
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};
// @lc code=end
