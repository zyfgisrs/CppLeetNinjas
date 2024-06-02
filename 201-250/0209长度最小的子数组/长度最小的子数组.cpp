#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int ans = nums.size() + 1;

    int sum = 0;
    int left = -1;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (sum >= target) {
        ans = std::min(ans, i - left);
        sum -= nums[++left];
      }
    }
    return ans == nums.size() + 1 ? 0 : ans;
  };
};