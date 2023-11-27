#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 4) return result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) continue;  // Skip duplicate numbers

      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j - 1] == nums[j])
          continue;  // Skip duplicate numbers

        int left = j + 1, right = nums.size() - 1;
        findFourSum(nums, target, i, j, left, right, result);
      }
    }

    return result;
  }

 private:
  void findFourSum(std::vector<int>& nums, int target, int i, int j, int left,
                   int right, std::vector<std::vector<int>>& result) {
    while (left < right) {
      long long sum =
          static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

      if (sum < target) {
        ++left;
      } else if (sum > target) {
        --right;
      } else {
        result.push_back({nums[i], nums[j], nums[left], nums[right]});

        while (left < right && nums[left] == nums[left + 1]) ++left;
        while (right > left && nums[right] == nums[right - 1]) --right;

        ++left;
        --right;
      }
    }
  }
};
