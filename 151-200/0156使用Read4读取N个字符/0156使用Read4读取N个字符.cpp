#include <algorithm>

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int total = 0;  // 总共读取的字符数
    char buf4[4];   // 临时缓存区

    while (total < n) {
      int count = read4(buf4);  // 从文件中读取字符

      // 确定这次可以从buf4复制多少字符到buf
      count = std::min(count, n - total);

      // 将buf4中的字符复制到buf
      for (int i = 0; i < count; i++) {
        buf[total++] = buf4[i];
      }

      // 如果文件中不再有更多字符，则终止循环
      if (count < 4) break;
    }

    return total;  // 返回实际读取的字符数
  }
};