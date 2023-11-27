#include <string>
#include <vector>
class Solution {
 public:
  int numDecodings(std::string s) {
    int n = s.size();
    std::vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;

    for (int i = 2; i < n + 1; i++) {
      if (s[i - 1] != '0') {
        dp[i] = dp[i - 1];
      }

      int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

      if (twoDigit >= 10 && twoDigit <= 26) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[n];
  }
};