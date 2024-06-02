struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <stack>

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) { pushAll(root); }

  int next() {
    TreeNode *tmpNode = nodeStack.top();
    nodeStack.pop();
    pushAll(tmpNode->right);
    return tmpNode->val;
  }

  bool hasNext() { return !nodeStack.empty(); }

 private:
  std::stack<TreeNode *> nodeStack;

  // 将从节点到其最左子节点的所有节点都推入栈中
  void pushAll(TreeNode *node) {
    while (node != nullptr) {
      nodeStack.push(node);
      node = node->left;
    }
  }
};