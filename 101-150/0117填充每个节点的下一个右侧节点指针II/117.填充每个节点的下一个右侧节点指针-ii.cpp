/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
#include <queue>
// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    std::queue<Node*> nodeQueue;
    if (root == nullptr) return root;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      for (int i = 0; i < count; i++) {
        Node* topNode = nodeQueue.front();
        nodeQueue.pop();
        if (i == count - 1) {
          topNode->next = nullptr;
        } else {
          topNode->next = nodeQueue.front();
        }
        if (topNode->left) nodeQueue.push(topNode->left);
        if (topNode->right) nodeQueue.push(topNode->right);
      }
    }
    return root;
  }
};
// @lc code=end
