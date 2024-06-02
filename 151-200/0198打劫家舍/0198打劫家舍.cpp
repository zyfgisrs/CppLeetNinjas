#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    if (nums.empty()) return 0;  // 如果数组为空，返回0

    int n = nums.size();
    if (n == 1) return nums[0];  // 如果只有一个房屋，只能偷窃这个房屋

    // dp数组，dp[i]表示偷窃到第i个房屋的最大金额
    std::vector<int> dp(n);
    dp[0] = nums[0];                     // 第一个房屋可以偷窃
    dp[1] = std::max(nums[0], nums[1]);  // 第二个房屋可以选择偷窃或者不偷窃

    for (int i = 2; i < n; ++i) {
      // 每个房屋可以选择偷窃或者不偷窃，取决于哪个金额更大
      // 如果偷窃当前房屋，那么就不能偷窃前一个房屋
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];  // 返回最后一个房屋的最大金额
  }
};