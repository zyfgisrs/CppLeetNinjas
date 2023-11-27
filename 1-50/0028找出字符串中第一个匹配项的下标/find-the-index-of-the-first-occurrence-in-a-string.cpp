#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    if (haystack.empty()) return -1;

    // Build the KMP table
    std::vector<int> next(needle.size(), 0);
    for (int i = 1, j = 0; i < needle.size(); ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        ++j;
      }
      next[i] = j;
    }

    // Use the KMP table to find the substring
    for (int i = 0, j = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
      if (j == needle.size()) {
        return i - j + 1;
      }
    }

    return -1;
  }
};
