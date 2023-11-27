/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> result;
    std::deque<int> q;  // 只存储元素的索引

    for (int i = 0; i < nums.size(); ++i) {
      // 删除不在窗口内的元素
      if (!q.empty() && q.front() == i - k) {
        q.pop_front();
      }

      // 维持队列的单调递减特性
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }

      q.push_back(i);

      // 当窗口完全包含在数组内时，将队列头部（当前窗口最大元素）添加到结果中
      if (i >= k - 1) {
        result.push_back(nums[q.front()]);
      }
    }
    return result;
  }
};
// @lc code=end
