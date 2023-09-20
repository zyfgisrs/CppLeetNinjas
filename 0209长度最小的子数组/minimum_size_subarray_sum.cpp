#include <iostream>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int left = -1;           //窗口左端
    int windowSum = 0;       //窗口中的数值之和
    int result = INT32_MAX;  //符合条件的最小窗口，即为返回的结果
    for (int right = 0; right < nums.size(); right++) {
      windowSum += nums[right];
      while (windowSum >= target) {
        result = std::min(result, right - left);
        windowSum -= nums[++left];
      }
    }
    return result == INT32_MAX ? 0 : result;
  };
};

int main() {
  std::vector<int> vec{2, 3, 1, 2, 4, 3};
  std::cout << Solution().minSubArrayLen(7, vec) << std::endl;
  return 0;
}