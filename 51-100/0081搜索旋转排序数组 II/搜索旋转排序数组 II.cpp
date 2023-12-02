#include <vector>

class Solution {
 public:
  bool search(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int midIndex = low + (high - low) / 2;

      if (nums[midIndex] == target) return true;

      if (nums[low] == nums[midIndex] && nums[high] == nums[midIndex]) {
        ++low;
        --high;
      } else if (nums[low] <= nums[midIndex]) {
        if (nums[low] <= target && target < nums[midIndex]) {
          high = midIndex - 1;
        } else {
          low = midIndex + 1;
        }
      } else {
        if (nums[high] >= target && target > nums[midIndex]) {
          low = midIndex + 1;
        } else {
          high = midIndex - 1;
        }
      }
    }
    return false;
  }
};
