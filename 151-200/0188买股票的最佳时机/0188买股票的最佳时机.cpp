#include <climits>
#include <vector>

class Solution {
 public:
  int maxProfit(int k, std::vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    // 当k非常大时，问题转化为不限交易次数
    if (k >= n / 2) {
      int maxProfit = 0;
      for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
          maxProfit += prices[i] - prices[i - 1];
        }
      }
      return maxProfit;
    }

    // n为天数（股票数组的大小），列为交易的次数
    std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, 0));
    // 计算在不同的交易次数限制下的最大利润
    for (int j = 1; j <= k; j++) {  // 遍历交易的次数
      int maxDiff = -prices[0];
      // maxDiff表示在当前交易次数下，到目前为止买入股票能获得的最大利润
      for (int i = 1; i < n; i++) {  // 第二天开始因为第一天不可能完成任何交易
        dp[i][j] = std::max(dp[i - 1][j], prices[i] + maxDiff);
        // dp[i - 1][j - 1]第i天之前j-1次交易能获得的最大利润
        maxDiff = std::max(maxDiff, dp[i - 1][j - 1] - prices[i]);
      }
    }

    return dp[n - 1][k];
  }
};