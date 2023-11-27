#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nums.size() - 2; ++i) {
      // Skip duplicates
      if (i > 0 && nums[i - 1] == nums[i]) continue;

      // No possible sum can be zero if the smallest number is positive
      if (nums[i] > 0) break;

      int left = i + 1;
      int right = nums.size() - 1;

      // Two-pointer technique
      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];

        if (sum < 0) {
          ++left;
        } else if (sum > 0) {
          --right;
        } else {
          result.push_back({nums[i], nums[left], nums[right]});

          // Skip duplicates for 'left'
          while (left < right && nums[left] == nums[left + 1]) ++left;

          // Skip duplicates for 'right'
          while (left < right && nums[right] == nums[right - 1]) --right;

          ++left;
          --right;
        }
      }
    }
    return result;
  }
};
