#include <vector>

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    int right = nums.size() - 1;
    int left = 0;

    std::vector<int> ans(nums.size());
    int index = nums.size() - 1;

    while (left <= right) {
      if (nums[left] * nums[left] >= nums[right] * nums[right]) {
        ans[index--] = nums[left] * nums[left];
        left++;
      } else {
        ans[index--] = nums[right] * nums[right];
        right--;
      }
    }
    return ans;
  }
};