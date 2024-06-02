#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    // 如果数组为空或只有一个元素，不需要旋转
    if (n <= 1) return;

    // 将 k 减去数组长度的余数，以避免多余的旋转
    k = k % n;

    // 反转整个数组
    reverse(nums.begin(), nums.end());
    // 反转前 k 个元素
    reverse(nums.begin(), nums.begin() + k);
    // 反转剩余的元素
    reverse(nums.begin() + k, nums.end());
  }
};

// 辅助函数，用于反转数组的一段
void reverse(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  while (start < end) {
    std::swap(*start, *end);
    start++;
    end--;
  }
}