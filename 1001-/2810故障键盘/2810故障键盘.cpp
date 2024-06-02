#include <string>

class Solution {
 public:
  std::string finalString(std::string s) {
    std::string ans;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != 'i') {
        ans.push_back(s[i]);
      } else {
        if (i < s.size() - 1 && s[i + 1] == 'i') {
          i++;
          continue;
        } else {
          reverseString(ans);
        }
      }
    }
    return ans;
  }

  void reverseString(std::string &str) {
    int left = 0;
    int right = str.size() - 1;
    while (left <= right) {
      char temp = str[left];
      str[left] = str[right];
      str[right] = temp;
      left++;
      right--;
    }
  }
};