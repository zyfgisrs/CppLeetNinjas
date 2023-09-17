# leetcode 面试题 02.07. 链表相交
* 两个链表有交点时，两个链表相交于公共节点
* 两个链表没有交点时，可以认为两个链表相交于nullptr。
* 综上所述，我们直接判断循环移动的指针是否相等就行了，若相等，不管是公共节点还是nullptr都直接返回。

~~~c++
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA;
    ListNode *nodeB = headB;
    while (nodeA != nodeB) {
      nodeA = nodeA == nullptr ? headB : nodeA->next;
      nodeB = nodeB == nullptr ? headA : nodeB->next;
    }
    return nodeA;
  }
};
~~~
