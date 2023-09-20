#include <iostream>
#include <vector>

class Solution {
 public:
  int search(std::vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      //防止溢出
      int middle = left + (right - left) / 2;
      if (target < nums[middle]) {
        right = middle - 1;
      } else if (target > nums[middle]) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;
  };

  int search2(std::vector<int> nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (target < nums[middle]) {
        right = middle;
      } else if (target > nums[middle]) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;
  };

  int search3(std::vector<int> nums, int target) {
    int left = -1;
    int right = nums.size();
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (target < nums[middle]) {
        right = middle;
      } else if (target > nums[middle]) {
        left = middle;
      } else {
        return middle;
      }
    }
    return -1;
  }
};

int main() {
  std::vector<int> nums = {-1, 1, 2, 3, 4, 5, 6};
  std::cout << Solution().search3(nums, 6) << std::endl;
  return 0;
}
