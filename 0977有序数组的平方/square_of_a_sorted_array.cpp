#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    std::vector<int> result(nums.size());
    int index = nums.size() - 1;
    while (left <= right) {
      if (nums[left] * nums[left] >= nums[right] * nums[right]) {
        result[index--] = nums[left] * nums[left];
        left++;
      } else {
        result[index--] = nums[right] * nums[right];
        right--;
      }
    }
    return result;
  }
};

int main() {
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  Solution s;
  auto res = Solution().sortedSquares(nums);
  for (const auto& i : res) {
    std::cout << i << " ";
  }
}