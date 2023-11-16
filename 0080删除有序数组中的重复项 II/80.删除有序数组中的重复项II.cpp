#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    // 如果数组长度小于等于2，直接返回原长度，因为不会有多余的重复
    if (nums.size() <= 2) {
      return nums.size();
    }

    // 初始化新数组的索引（指针）
    int newLength = 2;

    // 从第3个元素开始遍历数组
    for (int i = 2; i < nums.size(); i++) {
      // 如果当前元素与新数组倒数第二个元素不同，则将其添加到新数组中
      if (nums[i] != nums[newLength - 2]) {
        nums[newLength++] = nums[i];
      }
    }

    // 返回新数组的长度
    return newLength;
  }
};