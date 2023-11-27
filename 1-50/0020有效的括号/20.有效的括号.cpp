/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    if (s.empty()) {
      return true;
    }

    const char OPEN_PAREN = '(';
    const char CLOSE_PAREN = ')';
    const char OPEN_BRACE = '{';
    const char CLOSE_BRACE = '}';
    const char OPEN_BRACKET = '[';
    const char CLOSE_BRACKET = ']';

    std::stack<char> parenthesesStack;
    for (const char ch : s) {
      if (ch == OPEN_PAREN || ch == OPEN_BRACE || ch == OPEN_BRACKET) {
        parenthesesStack.push(ch);
      } else {
        if (parenthesesStack.empty() ||
            (ch == CLOSE_PAREN && parenthesesStack.top() != OPEN_PAREN) ||
            (ch == CLOSE_BRACKET && parenthesesStack.top() != OPEN_BRACKET) ||
            (ch == CLOSE_BRACE && parenthesesStack.top() != OPEN_BRACE)) {
          return false;
        }
        parenthesesStack.pop();
      }
    }
    return parenthesesStack.empty();
  }
};

// @lc code=end
