#include <string>

class Solution {
 public:
  int titleToNumber(std::string columnTitle) {
    long long ans = 0;  // 防止溢出
    for (char ch : columnTitle) {
      int num = ch - 'A' + 1;
      ans = ans * 26 + num;
    }
    return ans;
  }
};