#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";

    std::string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      prefix = commonPrefix(prefix, strs[i]);
      if (prefix.empty()) break;
    }

    return prefix;
  }

 private:
  std::string commonPrefix(const std::string& str1, const std::string& str2) {
    int length = std::min(str1.size(), str2.size());

    int index = 0;
    while (index < length && str1[index] == str2[index]) {
      index++;
    }

    return str1.substr(0, index);
  }
};
