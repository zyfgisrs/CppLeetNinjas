#include <algorithm>
#include <unordered_set>
#include <vector>


class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : num_set) {
      // Check if it's the start of a sequence
      if (num_set.find(num - 1) == num_set.end()) {
        int currentNum = num;
        int currentStreak = 1;

        while (num_set.find(currentNum + 1) != num_set.end()) {
          currentNum += 1;
          currentStreak += 1;
        }

        longestStreak = std::max(longestStreak, currentStreak);
      }
    }

    return longestStreak;
  }
};