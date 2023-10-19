#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums,
                                                  int lower, int upper) {
    nums.insert(nums.begin(), lower - 1);
    nums.push_back(upper + 1);
    std::vector<std::vector<int>> result;
    for (int i = 0, j = 1; i < nums.size() - 1; ++i, ++j) {
      if (nums[j] - nums[i] >= 2) {
        result.push_back({nums[i] + 1, nums[j] - 1});
      }
    }
    return result;
  }
};