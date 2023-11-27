#include <vector>

class Solution {
 public:
  bool search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        return true;
      }

      if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
        left++;
        right--;
      } else if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && nums[mid] > target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return false;
  }
};