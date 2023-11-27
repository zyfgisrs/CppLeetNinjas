#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int strLength = s.size();  // 字符串的长度
    int left = 0, right = 0;   // 定义左右指针
    int switchPoint = -1;  // 记录中间转换点，即第一个字符和第二个字符变换的地方
    int maxLength = 0;  // 记录满足条件的最长子串的长度

    // 遍历整个字符串
    while (right < strLength) {
      char firstChar = s[left];  // 获取第一个字符

      // 扩大右指针直到遇到与第一个字符不同的字符
      while (right < strLength && s[right] == firstChar) right++;

      // 如果已经到达字符串末尾，则计算长度并结束循环
      if (right == strLength) {
        maxLength = max(maxLength, right - left);
        break;
      }

      // 记录第二个字符的起始位置
      switchPoint = right;

      char secondChar = s[right];  // 获取第二个字符

      // 继续扩大右指针，只要遇到的字符是第一个或第二个字符之一
      while (right < strLength &&
             (s[right] == firstChar || s[right] == secondChar))
        right++;

      // 更新最长子串长度
      maxLength = max(maxLength, right - left);

      // 更新左指针到第二个字符的起始位置，并重置右指针，开始新的循环
      left = switchPoint;
      right = switchPoint;
    }

    return maxLength;  // 返回找到的最长子串的长度
  }
};