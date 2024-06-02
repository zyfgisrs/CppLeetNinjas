#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int left = 0, mid = 0, right = nums.size() - 1;

    while (mid <= right) {
      if (nums[mid] == 1) {
        mid++;
      } else if (nums[mid] == 0) {
        int temp = nums[left];
        nums[left++] = 0;
        nums[mid++] = temp;
      } else {
        int temp = nums[right];
        nums[right--] = 2;
        nums[mid] = temp;
      }
    }
  }
};