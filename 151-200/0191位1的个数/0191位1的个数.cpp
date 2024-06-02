#include <cstdint>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    // 使用按位与操作来统计1的个数
    while (n) {
      ans += n & 1;  // 如果n的最低位是1，就增加计数
      n = n >> 1;    // 右移一位，相当于除以2
    }
    return ans;
  }
};