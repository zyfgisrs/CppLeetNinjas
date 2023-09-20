/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start

#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stack;
    const std::string addition = "+";
    const std::string subtraction = "-";
    const std::string multiplication = "*";
    const std::string division = "/";
    for (const std::string str : tokens) {
      if (str != addition && str != multiplication && str != subtraction &&
          str != division) {
        stack.push(std::atoi(str.c_str()));
      } else {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();
        int res = 0;
        if (str == addition)
          res = num2 + num1;
        else if (str == subtraction)
          res = num2 - num1;
        else if (str == multiplication)
          res = num2 * num1;
        else
          res = num2 / num1;
        stack.push(res);
      }
    }
    return stack.top();
  }
};
// @lc code=end
