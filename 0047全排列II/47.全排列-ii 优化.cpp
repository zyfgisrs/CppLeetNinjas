/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <algorithm>
#include <unordered_set>
#include <vector>


// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::vector<bool> used(nums.size(), false);
    dfs(result, current, used, nums);
    return result;
  }

  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& current,
           std::vector<bool>& used, std::vector<int>& nums) {
    int n = nums.size();
    if (current.size() == n) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      used[i] = true;
      current.push_back(nums[i]);
      dfs(result, current, used, nums);
      used[i] = false;
      current.pop_back();
    }
  }
};
// @lc code=end
