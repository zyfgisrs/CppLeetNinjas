/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> combations;
    std::vector<int> current;
    dfs(combations, current, nums, 0);
    return combations;
  }

 private:
  void dfs(std::vector<std::vector<int>>& combintations,
           std::vector<int>& current, std::vector<int>& nums, int start) {
    combintations.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
      current.push_back(nums[i]);
      dfs(combintations, current, nums, i + 1);
      current.pop_back();
    }
  }
};
// @lc code=end
