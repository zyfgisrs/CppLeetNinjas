#include <queue>
#include <string>
#include <unordered_set>
#include <vector>


class Solution {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) {
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return 0;

    std::queue<std::pair<std::string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
      auto [word, length] = q.front();
      q.pop();

      if (word == endWord) return length;

      dict.erase(word);  // 避免重复处理

      for (int i = 0; i < word.size(); ++i) {
        char original_char = word[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          word[i] = c;
          if (dict.find(word) != dict.end()) {
            q.push({word, length + 1});
          }
        }
        word[i] = original_char;
      }
    }
    return 0;
  }
};
