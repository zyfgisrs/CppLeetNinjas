#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int res;
    for (int num : nums) {
      res ^= num;
    }
    return res;
  }
};