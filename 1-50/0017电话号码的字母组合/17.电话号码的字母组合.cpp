/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }
    const static std::vector<std::string> kDigitMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> combinations;
    std::string current;
    dfs(kDigitMap, 0, digits, current, combinations);
    return combinations;
  }

 private:
  void dfs(const std::vector<std::string> &kDigitMap, int index,
           const std::string &digits, std::string current,
           std::vector<std::string> &combinations) {
    if (index == digits.size()) {
      combinations.push_back(current);
      return;
    }

    std::string current_digits = kDigitMap[digits[index] - '0'];
    for (char ch : current_digits) {
      current.push_back(ch);
      dfs(kDigitMap, index + 1, digits, current, combinations);
      current.pop_back();
    }
  }
};
// @lc code=end
