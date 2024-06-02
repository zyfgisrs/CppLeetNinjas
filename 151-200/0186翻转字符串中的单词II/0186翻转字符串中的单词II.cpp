#include <vector>

class Solution {
 public:
  void reverseWords(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    swapChar(s, left, right);

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
      if ((i < s.size() - 1 && s[i + 1] == ' ') || i == s.size() - 1) {
        swapChar(s, index, i);
        index = i + 2;
      }
    }
  }

  void swapChar(std::vector<char>& s, int left, int right) {
    while (left < right) {
      std::swap(s[left++], s[right--]);
    }
  }
};