/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#include <vector>
#include <queue>
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        std::queue<TreeNode*> nodeQueue;
        if(root == nullptr) return result;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int count = nodeQueue.size();
            for(int i = 0; i < count; i++){
                TreeNode* topNode = nodeQueue.front();
                if(topNode->left) nodeQueue.push(topNode->left);
                if(topNode->right) nodeQueue.push(topNode->right);
                nodeQueue.pop();
                if(i == count -1){
                    result.push_back(topNode->val);
                }
            }
        }
        return result;
    }
};
// @lc code=end

