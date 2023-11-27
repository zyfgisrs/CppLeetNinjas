/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

#include <stack>
class MyQueue {
 private:
  std::stack<int> stack1;
  std::stack<int> stack2;
  int size;

 public:
  MyQueue() { size = 0; }

  void push(int x) {
    stack1.push(x);
    size++;
  }

  int pop() {
    while (!stack1.empty()) {
      int top = stack1.top();
      stack1.pop();
      stack2.push(top);
    }
    int result = stack2.top();
    stack2.pop();
    while (!stack2.empty()) {
      int top = stack2.top();
      stack2.pop();
      stack1.push(top);
    }
    size--;
    return result;
  }

  int peek() {
    while (!stack1.empty()) {
      int top = stack1.top();
      stack1.pop();
      stack2.push(top);
    }
    int result = stack2.top();
    while (!stack2.empty()) {
      int top = stack2.top();
      stack2.pop();
      stack1.push(top);
    }
    return result;
  }

  bool empty() { return size == 0; }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
