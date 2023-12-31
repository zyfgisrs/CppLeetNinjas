Sure, here's the LeetCode problem "110. 平衡二叉树" formatted in markdown:

---

# 110. 平衡二叉树

## 题目描述

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
> 一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。

### 示例 1：

![示例1图片](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

输入：root = [3,9,20,null,null,15,7]
输出：true

### 示例 2：

![示例2图片](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

### 示例 3：

输入：root = []
输出：true

### 提示：

- 树中的节点数在范围 [0, 5000] 内
- -10^4 <= Node.val <= 10^4

---

### 1. 递归方法：

#### 代码实现思路：
1. 使用递归函数检查每个节点的左右子树是否平衡。
2. 如果任一子树不平衡，返回-1。
3. 如果子树平衡，返回其高度。
4. 对于每个节点，如果左右子树的高度差超过1，则返回-1。

#### 算法思想：
- **后序遍历**：首先检查左右子树是否平衡，然后检查当前节点。

#### 解题技巧：
- 使用-1作为特殊标记，表示子树是不平衡的。这允许我们在发现不平衡的子树时立即停止递归。

#### 时间复杂度：
- \(O(n)\)，其中 \(n\) 是树中的节点数。每个节点被访问一次。

---

### 2. 迭代方法：

#### 代码实现思路：
1. 使用栈模拟后序遍历的过程。
2. 定义一个结构体 `Element` 来保存每个节点的信息。
3. 使用哈希表存储每个节点的高度。
4. 在遍历过程中，根据每个节点的状态决定下一步操作。

#### 算法思想：
- **后序遍历**：使用一个栈和节点的状态来模拟后序遍历的过程。
- **哈希表存储**：使用哈希表保存每个节点的高度，以避免重复计算。

#### 解题技巧：
- 使用 `state` 变量在不使用多个栈的情况下模拟后序遍历。
- 利用哈希表避免重复计算，使算法更加高效。

#### 时间复杂度：
- \(O(n)\)，其中 \(n\) 是树中的节点数。每个节点被访问一次。

---

**总结**：

平衡二叉树的检查基于每个节点的左右子树的高度差。虽然递归方法更为直观和简洁，但迭代方法可以在特定的场景（例如树的深度非常大）中提供更好的性能。理解后序遍历的概念是实现这两种方法的关键。
