/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> combinations;
    std::vector<int> current;
    dfs(combinations, current, 0, target, candidates);
    return combinations;
  }

  void dfs(std::vector<std::vector<int>>& combinations,
           std::vector<int>& current, int index, int target,
           std::vector<int>& candidates) {
    if (target == 0) {
      combinations.push_back(current);
      return;
    }

    for (int i = index; i < candidates.size(); ++i) {
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }

      if (target - candidates[i] >= 0) {
        current.push_back(candidates[i]);
        dfs(combinations, current, i + 1, target - candidates[i], candidates);
        current.pop_back();
      }
    }
  }
};
// @lc code=end
