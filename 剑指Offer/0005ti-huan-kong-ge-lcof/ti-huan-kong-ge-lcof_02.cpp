#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    int originalLength = s.length();
    int countSpace = 0;
    for (int i = 0; i < originalLength; i++) {
      if (s[i] == ' ') countSpace++;
    }
    s.resize(originalLength + countSpace * 2);
    int readPtr = originalLength - 1;
    int writePtr = s.length() - 1;
    while (readPtr >= 0) {
      if (s[readPtr] == ' ') {
        s[writePtr--] = '0';
        s[writePtr--] = '2';
        s[writePtr--] = '%';
      } else {
        s[writePtr--] = s[readPtr];
      }
      readPtr--;
    }
    return s;
  }
};