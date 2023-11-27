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
    std::string result;
    for (const char ch : s) {
      if (result.empty() || result.back() != ch) {
        result += ch;
      } else {
        result.pop_back();
      }
    }
    return result;
  }
};
// @lc code=end
