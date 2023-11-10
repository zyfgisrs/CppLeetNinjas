#include <vector>

class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) return false;

    // 初始化一个数组，包含所有丑数的因子
    const std::vector<int> factors = {2, 3, 5};

    // 使用范围for循环来简化代码
    for (int factor : factors) {
      // 只要n能够被因子整除，就继续除以该因子
      while (n % factor == 0) n /= factor;
    }

    // 如果n被因子除尽，它就是丑数
    return n == 1;
  }
};
