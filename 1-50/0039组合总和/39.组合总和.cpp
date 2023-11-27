/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> combinations;
    std::vector<int> current;
    dfs(candidates, combinations, current, target, 0);
    return combinations;
  }

  void dfs(std::vector<int>& candidates,
           std::vector<std::vector<int>>& combinations,
           std::vector<int>& current, int target, int index) {
    if (target == 0) {
      combinations.push_back(current);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (target >= candidates[i]) {
        current.push_back(candidates[i]);
        dfs(candidates, combinations, current, target - candidates[i], i);
        current.pop_back();
      }
    }
  }
};
// @lc code=end
