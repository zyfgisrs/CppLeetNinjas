#include <stack>

class MinStack {
 public:
  std::stack<int> s;
  std::stack<int> minS;
  MinStack() {}

  void push(int val) {
    s.push(val);

    if (minS.empty() || minS.top() >= val) {
      minS.push(val);
    }
  }

  void pop() {
    int val = s.top();
    s.pop();

    if (val == minS.top()) {
      minS.pop();
    }
  }

  int top() { return s.top(); }

  int getMin() { return min.top(); }
};