/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> vec;
    dfs(n, k, 0, vec, result);
    return result;
  }

  void dfs(int n, int k, int index, std::vector<int>& vec,
           std::vector<std::vector<int>>& res) {
    if (vec.size() == k) {
      res.push_back(vec);
      return;
    }

    for (int i = index; i < n; i++) {
      if (vec.size() + (n - i) < k) break;
      vec.push_back(i + 1);
      dfs(n, k, i + 1, vec, res);
      vec.pop_back();
    }
  }
};
// @lc code=end
