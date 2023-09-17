#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseStr(std::string s, int k) {
    int len = s.length();
    int index = 0;

    while (index < len) {
      int count =
          std::min(k, len - index);  // Determine the actual length to reverse
      reverseStr(s, index, count);   // Reverse k characters or the remaining
      index += 2 * k;  // Move the index by 2k to go to the next chunk
    }

    return s;
  }

 private:
  void reverseStr(std::string& s, int left, int len) {
    int right = left + len - 1;
    while (left < right) {
      std::swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};
