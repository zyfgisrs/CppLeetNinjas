#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
    int n = s.size();
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      // 不分割的情况
      dp[i] = dp[i - 1] + 1;

      // 尝试分割
      for (const std::string& word : dictionary) {
        int len = word.length();
        if (i >= len && s.substr(i - len, len) == word) {
          dp[i] = std::min(dp[i], dp[i - len]);
        }
      }
    }
    return dp[n];
  }
};
