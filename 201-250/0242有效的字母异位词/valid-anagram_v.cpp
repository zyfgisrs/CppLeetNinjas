#include <iostream>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      //如果s和t的长度不一样，直接返回false
      return false;
    }

    int record[26] = {0};
    for (int i = 0; i < s.length(); ++i) {
      // s[i] - 'a'是将s[i]转换为数字，a对应0，b对应1，c对应2，以此类推
      record[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); ++i) {
      //如果t中的字符比s中的多，直接返回false
      if (--record[t[i] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};