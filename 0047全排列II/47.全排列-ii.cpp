/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::vector<int> used(nums.size(), 0);
    dfs(result, current, used, nums);
    return result;
  }

  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& current,
           std::vector<int>& used, std::vector<int>& nums) {
    int n = nums.size();
    if (current.size() == n) {
      result.push_back(current);
      return;
    }

    std::unordered_set<int> set;
    for (int i = 0; i < n; i++) {
      if (set.find(nums[i]) != set.end() || used[i] == 1) continue;
      used[i] = 1;
      current.push_back(nums[i]);
      set.insert(nums[i]);
      dfs(result, current, used, nums);
      used[i] = 0;
      current.pop_back();
    }
  }
};
// @lc code=end
