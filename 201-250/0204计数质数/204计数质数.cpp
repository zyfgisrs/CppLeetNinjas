#include <vector>
// 质数（素数）是指一个大于1的自然数，它除了1和它本身以外，不能被其他自然数整除
class Solution {
 public:
  int countPrimes(int n) {
    std::vector<bool> isPrime(n, true);  // 初始化一个布尔数组，所有值初始为true
    int count = 0;

    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {  // 如果当前数字是质数
        ++count;         // 增加质数计数
        // 将所有当前质数的倍数标记为非质数
        for (long long j = (long long)i * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    return count;
  }
};