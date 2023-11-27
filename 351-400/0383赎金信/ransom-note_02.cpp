#include <string>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    for (const char& ch : magazine) {
      record[ch - 'a']++;
    }

    for (const char& ch : ransomNote) {
      if (--record[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};