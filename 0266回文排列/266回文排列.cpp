#include <string>
#include <unordered_map>

class Solution {
 public:
  bool canPermutePalindrome(std::string s) {
    std::unordered_map<char, int> countMap;
    int oddCount = 0;

    for (char ch : s) {
      countMap[ch]++;
      // 如果字符出现次数为奇数，增加oddCount；如果为偶数，减少oddCount。
      oddCount += countMap[ch] % 2 ? 1 : -1;
    }

    // 回文串的排列中，最多只能有一个字符出现奇数次。
    return oddCount <= 1;
  }
};