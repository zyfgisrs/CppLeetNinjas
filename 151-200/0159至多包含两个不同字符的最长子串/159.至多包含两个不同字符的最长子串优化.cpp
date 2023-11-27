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
      map[s[right]] = right;

      right++;

      if (map.size() > 2) {
        int min = INT_MAX;
        for (std::pair<char, int> it : map) {
          min = std::min(it.second, min);
        }
        map.erase(s[min]);
        left = min + 1;
      }
      max_length = std::max(max_length, right - left);
    }
    return max_length;
  }
};