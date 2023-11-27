#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int vowelStrings(std::vector<std::string>& words, int left, int right) {
    std::unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
    int result = 0;
    for (int i = left; i <= right; i++) {
      std::string word = words[i];
      if (set.find(word.front()) != set.end() &&
          set.find(word.back()) != set.end()) {
        result++;
      }
    }
    return result;
  }
};