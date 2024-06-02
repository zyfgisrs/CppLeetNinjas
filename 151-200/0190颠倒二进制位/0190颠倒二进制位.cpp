#include <cstdint>

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
      result = (result << 1) | (n & 1);  // 将n的最低位移动到result的最高位
      n = n >> 1;                        // 右移n，准备下一次循环
    }
    return result;
  }
};