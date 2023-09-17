#include <iostream>
#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int fastIndex = 0;
    int slowIndex = 0;
    for (; fastIndex < nums.size(); fastIndex++) {
      if (nums[fastIndex] != val) {
        nums[slowIndex++] = nums[fastIndex];
      }
    }
    return slowIndex;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {3, 2, 2, 3};
  std::cout << s.removeElement(nums, 3) << std::endl;
  return 0;
}