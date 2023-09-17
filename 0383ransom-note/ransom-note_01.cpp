#include <unordered_map>

using namespace std;

class Solution {
  using CharType = char;
  using CountType = int;

 public:
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<CharType, CountType> char_to_count_map;
    for (const char ch : magazine) {
      char_to_count_map[ch]++;
    }
    for (const char ch : ransomNote) {
      if (char_to_count_map.find(ch) == char_to_count_map.end() ||
          --char_to_count_map[ch] < 0) {
        return false;
      }
    }
    return true;
  }
};