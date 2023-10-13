/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <string>
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> combinations;
    std::string str;
    if (s.size() < 4 || s.size() > 12) return combinations;
    dfs(combinations, str, s, 0, 0);
    return combinations;
  }

  void dfs(std::vector<std::string>& combinations, std::string& current,
           std::string& s, int start, int num) {
    if (start == s.size() && num == 4) {
      combinations.push_back(current);
      return;
    }

    if (num >= 4) {
      return;
    }

    for (int i = start + 1; i <= start + 3 & i <= s.size(); ++i) {
      std::string str = s.substr(start, i - start);
      if (!isVaild(str)) continue;

      int n = current.size();
      if (n > 0) {
        current += ".";
      }
      current += str;

      dfs(combinations, current, s, i, num + 1);
      current = current.substr(0, n);
    }
  }

  bool isVaild(std::string s) {
    int n = s.size();
    if (n > 1 && s[0] == '0') {
      return false;
    }
    int num = std::stoi(s);
    if (num > 255) {
      return false;
    }

    return true;
  }
};
// @lc code=end
