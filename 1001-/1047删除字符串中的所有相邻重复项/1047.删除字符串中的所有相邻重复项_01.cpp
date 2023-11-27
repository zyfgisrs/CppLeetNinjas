/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <stack>
#include <string>

// @lc code=start
class Solution {
 public:
  std::string removeDuplicates(std::string s) {
    std::stack<char> stack;
    std::string result;
    for (const char ch : s) {
      if (stack.empty() || stack.top() != ch) {
        stack.push(ch);
      } else {
        stack.pop();
      }
    }
    while (!stack.empty()) {
      result = stack.top() + result;
      stack.pop();
    }
    return result;
  }
};
// @lc code=end
