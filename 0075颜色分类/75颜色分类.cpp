#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high) {
      if (nums[mid] == 2) {
        int temp = nums[mid];
        nums[mid] = nums[high];
        nums[high] = temp;
        high--;
      } else if (nums[mid] == 0) {
        int temp = nums[mid];
        nums[mid] = nums[low];
        nums[low] = temp;
        low++;
      } else {
        mid++;
      }
    }
  }
};