/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::vector<int> used(nums.size(), 0);
    dfs(result, current, used, nums);
    return result;
  }

 private:
  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& current,
           std::vector<int>& used, std::vector<int>& nums) {
    int n = nums.size();
    if (current.size() == n) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (used[i] == 1) continue;
      used[i] = 1;
      current.push_back(nums[i]);
      dfs(result, current, used, nums);
      used[i] = 0;
      current.pop_back();
    }
  }
};
// @lc code=end
