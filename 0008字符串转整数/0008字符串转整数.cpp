#include <climits>
#include <string>

class Solution {
 public:
  int myAtoi(std::string s) {
    int strLength = s.size();
    int currentIndex = 0;
    int result = 0;
    int sign = 1;  // 默认为正

    // 跳过前导空格
    while (currentIndex < strLength && s[currentIndex] == ' ') {
      currentIndex++;
    }

    // 检查符号
    if (currentIndex < strLength) {
      if (s[currentIndex] == '-') {
        sign = -1;
        currentIndex++;
      } else if (s[currentIndex] == '+') {
        currentIndex++;
      }
    }

    // 转换数字并检查溢出
    while (currentIndex < strLength && isdigit(s[currentIndex])) {
      int digit = s[currentIndex] - '0';

      // 检查溢出
      if (result > INT_MAX / 10 ||
          (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }

      result = result * 10 + digit;
      currentIndex++;
    }

    return sign * result;
  }
};