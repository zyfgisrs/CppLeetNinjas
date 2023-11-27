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
    int n = s.size();
    // Initialize a 2D array to store palindrome information
    std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if ((s[i] == s[j]) && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
          isPalindrome[i][j] = true;
        }
      }
    }

    std::vector<std::vector<std::string>> combinations;
    std::vector<int> current;
    dfs(combinations, current, s, isPalindrome, 0);
    return combinations;
  }

 private:
  void dfs(std::vector<std::vector<std::string>>& combinations,
           std::vector<int>& current, const std::string& s,
           const std::vector<std::vector<bool>>& isPalindrome, int start) {
    if (start == s.size()) {
      std::vector<std::string> combination;
      int prevIndex = 0;
      for (int index : current) {
        combination.push_back(s.substr(prevIndex, index - prevIndex));
        prevIndex = index;
      }
      combinations.push_back(combination);
      return;
    }

    for (int i = start + 1; i <= s.size(); ++i) {
      if (isPalindrome[start][i - 1]) {
        current.push_back(i);
        dfs(combinations, current, s, isPalindrome, i);
        current.pop_back();
      }
    }
  }
};
// @lc code=end
