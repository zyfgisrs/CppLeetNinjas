
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums,
                                                  int lower, int upper) {
    std::vector<std::vector<int>> result;
    if (nums.size() == 0) {
      result.push_back({lower, upper});
      return result;
    }
    if (nums[0] > lower) {
      result.push_back({lower, nums[0] - 1});
    }

    for (int i = 0, j = 1; i < nums.size() - 1; ++i, ++j) {
      if (nums[i] < nums[j] - 1) {
        result.push_back({nums[i] + 1, nums[j] - 1});
      }
    }

    if (nums[nums.size() - 1] < upper) {
      result.push_back({nums[nums.size() - 1] + 1, upper});
    }

    return result;
  }
};