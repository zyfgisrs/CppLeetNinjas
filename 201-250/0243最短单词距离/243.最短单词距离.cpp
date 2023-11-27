#include <string>
#include <vector>

class Solution {
 public:
  // 单词列表是按顺序遍历的，所以我们总是在处理两个单词最近的出现，这保证了距离的计算是基于最新的邻近位置。
  int shortestDistance(std::vector<std::string>& wordsDict, std::string word1,
                       std::string word2) {
    int word1_index = -1;
    int word2_index = -1;
    int min_distance = INT_MAX;
    for (int i = 0; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) word1_index = i;
      if (wordsDict[i] == word2) word2_index = i;

      if (word1_index >= 0 && word2_index >= 0) {
        min_distance =
            std::min(std::abs(word1_index - word2_index), min_distance);
      }
    }
    return min_distance;
  }
};