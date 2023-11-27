#include <string>
#include <vector>

class Solution {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int lenS1 = s1.size(), lenS2 = s2.size(), lenS3 = s3.size();

    if (lenS1 + lenS2 != lenS3) {
      return false;
    }

    std::vector<int> dp(lenS2 + 1, false);
    dp[0] = true;

    for (int i = 0; i <= lenS1; ++i) {
      for (int j = 0; j <= lenS2; ++j) {
        int p = i + j;
        if (i > 0) {
          dp[j] = dp[j] && (s1[i - 1] == s3[p - 1]);
        }
        if (j > 0) {
          dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[p - 1]);
        }
      }
    }

    return dp[lenS2];
  }
};
