/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> current;

    dfs(combinations, current, nums, 0);

    return combinations;
  }

 private:
  void dfs(std::vector<std::vector<int>>& combinations,
           std::vector<int>& current, std::vector<int>& nums, int start) {
    if (current.size() >= 2) {
      combinations.push_back(current);
    }

    std::unordered_set<int> set;
    for (int i = start; i < nums.size(); ++i) {
      if (!current.empty() && current.back() > nums[i] ||
          set.find(nums[i]) != set.end()) {
        continue;
      }
      set.insert(nums[i]);
      current.push_back(nums[i]);
      dfs(combinations, current, nums, i + 1);
      current.pop_back();
    }
  }
};
// @lc code=end
