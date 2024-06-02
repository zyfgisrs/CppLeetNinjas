#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::vector<int> charIndex(256, -1);
    int maxLen = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      if (charIndex[s[right]] >= left) {
        left = charIndex[s[right]] + 1;
      }

      charIndex[s[right]] = right;
      maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};