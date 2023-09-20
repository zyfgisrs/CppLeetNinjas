# leetcode 242. 有效的字母异位词

* 自己编写的代码:
~~~c++
class Solution {
 public:
  bool isAnagram(string s, string t) {
    std::unordered_map<char, int> map;
    for (const auto& element : s) {
      if (map.count(element) == 0) {
        map[element] = 1;
      } else {
        map[element] = map[element] + 1;
      }
    }

    for (const auto& element : t) {
      if (map.count(element) == 0 || map[element] == 0) {
        return false;
      }
      map[element] = map[element] - 1;
    }

    for(const auto& element: map){
        if(element.second != 0){
            return false;
        }
    }
    return true;
  }
};
~~~
* 存在的问题：
  - 添加一个对两个字符串长度的比较，如果它们的长度不同，那么它们就不能是anagram。
  - 对于如何处理哈希表中的字符计数，可以使用更简洁的代码。
  - 在检查字符计数时，无需使用count()方法，直接查找和更新即可。
  - 在完成t的遍历之后，无需再次遍历整个哈希表，因为在前面已经判断过了s和t的长度是否相等，在遍历t的时候已经判断了t的某个字符比s多的情况，那么就不需要再考虑t的某个字符比s少的情况（字符数量相等）。

* 修改后的代码：
~~~c++
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        //如果s和t的长度不一样，直接返回false
        return false;
    }
    //创建一个map
    std::unordered_map<char, int> map;
    for (const auto& element : s) {
      map[element]++;//map[element] = map[element] + 1;
    }

    for (const auto& element : t) {
      if(--map[element] < 0){
        //如果map[element] < 0，说明t中的字符比s中的多
        return false;
      }
    }
    return true;
  }
};
~~~

* 使用数组作为哈希表
~~~c++
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        //如果s和t的长度不一样，直接返回false
        return false;
    }

    int record[26] = {0};
    for(int i = 0; i < s.length(); ++i){
        //s[i] - 'a'是将s[i]转换为数字，a对应0，b对应1，c对应2，以此类推
        record[s[i] - 'a']++;
    }

    for(int i = 0; i < t.length(); ++i){
        //如果t中的字符比s中的多，直接返回false
        if(--record[t[i] - 'a'] < 0){
            return false;
        }
    }
    return true;
  }
};
~~~