/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> current_combination;
    findCombinations(k, n, 1, 0, current_combination, combinations);
    return combinations;
  }

 private:
  void findCombinations(int k, int n, int start, int sum,
                        std::vector<int>& current,
                        std::vector<std::vector<int>>& combinations) {
    // Base case: if the current combination is valid, add it to the results.
    if (sum == n && current.size() == k) {
      combinations.push_back(current);
      return;
    }

    // Recursive case: explore possible numbers to add to the combination.
    for (int i = start; i <= 9; ++i) {
      // Pruning: skip the rest if the current number makes the sum too large.
      if (sum + i > n) break;

      // Add the current number and explore further.
      current.push_back(i);
      findCombinations(k, n, i + 1, sum + i, current, combinations);
      current.pop_back();  // Backtrack to explore other combinations.
    }
  }
};
// @lc code=end
