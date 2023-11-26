#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[right]) {
        left = mid + 1;  // left的目标是指向最小值
        // nums[mid] > nums[right]，说明mid一定在最小值的左边。
      } else {
        right = mid;
        // nums[mid] < nums[right]，说明mid一定在最小值右边或本身就是最小值。
      }
    }

    return nums[left];  // 返回的是left
  }
};