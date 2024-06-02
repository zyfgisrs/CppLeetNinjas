#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0;                    // 左指针初始在数组开始位置
    int right = numbers.size() - 1;  // 右指针初始在数组末尾位置

    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        // 由于题目中数组的下标从1开始，因此需要+1
        return {left + 1, right + 1};
      } else if (sum < target) {
        left++;  // 移动左指针
      } else {
        right--;  // 移动右指针
      }
    }
    return {};  // 如果没有找到，则返回空数组
  }
};