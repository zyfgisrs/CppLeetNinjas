/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
#include <queue>
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node *root) {
    std::vector<std::vector<int>> result;
    std::queue<Node *> nodeQueue;
    if (root == nullptr) return result;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
      int count = nodeQueue.size();
      std::vector<int> vec;
      for (int i = 0; i < count; i++) {
        Node *topNode = nodeQueue.front();
        std::vector<Node *> children = topNode->children;
        if (children.size() > 0) {
          for (Node *node : children) {
            nodeQueue.push(node);
          }
        }
        nodeQueue.pop();
        vec.push_back(topNode->val);
      }
      result.push_back(vec);
    }
    return result;
  }
};
// @lc code=end
