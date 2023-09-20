#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      //如果s和t的长度不一样，直接返回false
      return false;
    }
    //创建一个map
    std::unordered_map<char, int> map;
    for (const auto& element : s) {
      map[element]++;  // map[element] = map[element] + 1;
    }

    for (const auto& element : t) {
      if (--map[element] < 0) {
        //如果map[element] < 0，说明t中的字符比s中的多
        return false;
      }
    }
    return true;
  }
};