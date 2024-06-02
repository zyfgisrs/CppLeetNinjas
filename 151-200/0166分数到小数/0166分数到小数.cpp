#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }

    std::string result;
    // 处理负数情况
    if (numerator < 0 ^ denominator < 0) {
      result.append("-");
    }

    // 使用长整型防止溢出
    long long n = llabs(numerator);
    long long d = llabs(denominator);
    long long integerPart = n / d;
    result.append(std::to_string(integerPart));

    // 处理小数部分
    long long remainder = n % d;
    if (remainder == 0) {
      return result;
    }

    result.append(".");
    std::unordered_map<long long, int> remainderMap;
    while (remainder != 0) {
      // 检查是否已经出现过这个余数，若出现则开始循环
      if (remainderMap.find(remainder) != remainderMap.end()) {
        result.insert(remainderMap[remainder], "(");
        result.append(")");
        break;
      }

      // 记录当前余数的位置
      remainderMap[remainder] = result.size();
      remainder *= 10;
      result.append(std::to_string(remainder / d));
      remainder %= d;
    }

    return result;
  }
};