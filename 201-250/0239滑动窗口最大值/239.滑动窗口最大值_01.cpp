/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
 private:
  class MonotonicQueue {
   public:
    std::deque<int> data;

    void pop(int value) {
      if (!data.empty() && value == data.front()) {
        data.pop_front();
      }
    }

    void push(int value) {
      while (!data.empty() && data.back() < value) {
        data.pop_back();
      }
      data.push_back(value);
    }

    int front() { return data.front(); }
  };

 public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> result;
    MonotonicQueue mq;
    for (int i = 0; i < k; ++i) {
      mq.push(nums[i]);
    }
    result.push_back(mq.front());
    for (int i = k; i < nums.size(); ++i) {
      mq.pop(nums[i - k]);
      mq.push(nums[i]);
      result.push_back(mq.front());
    }
    return result;
  }
};
// @lc code=end
