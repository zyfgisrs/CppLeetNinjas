#include <algorithm>
#include <vector>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(n);
    dp[0] = 1;                   // 默认1是最小的丑数
    int i2 = 0, i3 = 0, i5 = 0;  // 初始化指针的位置在数组开始位置

    for (int i = 1; i < n; ++i) {
      int next2 = dp[i2] * 2, next3 = dp[i3] * 3, next5 = dp[i5] * 5;
      dp[i] = std::min({next2, next3, next5});
      if (dp[i] == next2) ++i2;
      if (dp[i] == next3) ++i3;
      if (dp[i] == next5) ++i5;
    }

    return dp.back();
  }
};
