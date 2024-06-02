#include <string>
#include <vector>

class Solution {
 public:
  int minCut(std::string s) {
    int n = s.size();
    std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
    std::vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
      isPalindrome[i][i] = true;
    }
    for (int len = 2; len <= n; ++len) {
      for (int start = 0; start <= n - len; ++start) {
        int end = start + len - 1;
        if (len == 2) {
          isPalindrome[start][end] = (s[start] == s[end]);
        } else {
          isPalindrome[start][end] =
              (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (isPalindrome[0][i]) {
        dp[i] = 0;
        continue;
      }
      dp[i] = i;
      for (int j = 0; j < i; ++j) {
        if (isPalindrome[j + 1][i]) {
          dp[i] = std::min(dp[i], dp[j] + 1);
        }
      }
    }

    return dp[n - 1];
  }
};
