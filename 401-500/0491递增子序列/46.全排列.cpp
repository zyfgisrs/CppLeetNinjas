/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(result, path, nums);
    return result;
  }

  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& path,
           std::vector<int>& nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (std::find(path.begin(), path.end(), nums[i]) != path.end()) continue;
      path.push_back(nums[i]);
      dfs(result, path, nums);
      path.pop_back();
    }
  }
};
// @lc code=end
