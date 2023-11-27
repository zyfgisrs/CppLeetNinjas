#include <string>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::unordered_map<char, int> map;

    int left = 0;
    int right = 0;
    int max_length = 0;
    while (right < s.size()) {
      map[s[right]]++;

      right++;

      while (map.size() > 2) {
        map[s[left]]--;

        if (map[s[left]] == 0) {
          map.erase(s[left]);
        }
        left++;
      }

      max_length = std::max(max_length, right - left);
    }
    return max_length;
  }
};