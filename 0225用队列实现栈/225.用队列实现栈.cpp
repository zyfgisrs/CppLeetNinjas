/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
// @lc code=start
class MyStack {
 private:
  std::queue<int> queue1;
  std::queue<int> queue2;

 public:
  MyStack() {}

  void push(int x) {
    queue2.push(x);
    while (!queue1.empty()) {
      queue2.push(queue1.front());
      queue1.pop();
    }
    std::swap(queue1, queue2);
  }

  int pop() {
    int res = queue1.front();
    queue1.pop();
    return res;
  }

  int top() { return queue1.front(); }

  bool empty() { return queue1.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
