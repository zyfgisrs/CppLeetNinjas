/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> combintations;
    std::vector<std::string> current;
    dfs(combintations, current, s, 0);
    return combintations;
  }

  void dfs(std::vector<std::vector<std::string>>& combinations,
           std::vector<std::string>& current, std::string& s, int start) {
    if (start >= s.size()) {
      combinations.push_back(current);
      return;
    }

    for (int i = start + 1; i <= s.size(); ++i) {
      std::string str = s.substr(start, i - start);
      if (isPalindrome(str)) {
        current.push_back(str);
        dfs(combinations, current, s, i);
        current.pop_back();
      }
    }
  }

  bool isPalindrome(std::string& str) {
    int n = str.size();
    int left = 0;
    int right = n - 1;
    while (left < right) {
      if (str[left] != str[right]) return false;
      left++;
      right--;
    }
    return true;
  }
};
// @lc code=end
