#include <string>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    // Check for empty string
    if (s.empty()) return s;

    removeExtraSpaces(s);

    // Reverse the entire string
    reverseStr(0, s.length() - 1, s);

    int start = 0;
    int end = 0;

    // Reverse individual words
    for (; end < s.length(); ++end) {
      if (s[end] == ' ') {
        reverseStr(start, end - 1, s);
        start = end + 1;
      }
    }

    // Reverse the last word
    reverseStr(start, end - 1, s);

    return s;
  }

 private:
  void removeExtraSpaces(string& s) {
    int readPointer = 0, writePointer = 0;

    // Skip leading spaces
    while (s[readPointer] == ' ') {
      ++readPointer;
    }

    // Remove extra spaces
    for (; readPointer < s.length(); ++readPointer) {
      if (s[readPointer] == ' ' && s[readPointer - 1] == ' ') {
        continue;
      }
      s[writePointer++] = s[readPointer];
    }

    // Remove trailing space if any
    if (s[writePointer - 1] == ' ') {
      s.resize(writePointer - 1);
    } else {
      s.resize(writePointer);
    }
  }

  void reverseStr(int left, int right, string& s) {
    while (left < right) {
      swap(s[left++], s[right--]);
    }
  }
};
