/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> combintations;
    std::vector<int> current;
    dfs(combintations, current, nums, 0);
    return combintations;
  }

  void dfs(std::vector<std::vector<int>>& combintations,
           std::vector<int>& current, std::vector<int>& nums, int start) {
    combintations.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) continue;

      current.push_back(nums[i]);
      dfs(combintations, current, nums, i + 1);
      current.pop_back();
    }
  }
};
// @lc code=end
