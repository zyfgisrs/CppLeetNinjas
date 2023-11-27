#include <string>
#include <vector>
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    int n = s.size();
    int maxlen = 1;
    int left = 0;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          dp[i][j] = len == 2 || dp[i + 1][j - 1];
          if (dp[i][j] && len > maxlen) {
            maxlen = len;
            left = i;
          }
        }
      }
    }
    return s.substr(left, maxlen);
  }
};