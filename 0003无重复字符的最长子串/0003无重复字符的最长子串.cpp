#include <string>
#include <unordered_map>
class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> lastPosition;
    int maxLength = 0, start = 0;

    for (int i = 0; i < s.size(); i++) {
      // 如果字符s[i]之前出现过，则更新start
      if (lastPosition.find(s[i]) != lastPosition.end()) {
        start = std::max(start, lastPosition[s[i]] + 1);
      }

      // 更新字符s[i]的最新位置
      lastPosition[s[i]] = i;

      // 更新最大长度
      maxLength = std::max(maxLength, i - start + 1);
    }
    return maxLength;
  }
};