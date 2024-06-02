#include <queue>
#include <string>
#include <unordered_set>
#include <vector>


class Solution {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) {
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    // 快速检查 endWord 是否在 wordList 中
    if (wordSet.find(endWord) == wordSet.end()) {
      return 0;
    }

    // 初始化两个方向的搜索队列
    std::unordered_set<std::string> beginSet, endSet;
    beginSet.insert(beginWord);
    endSet.insert(endWord);

    int step = 1;  // 初始化步数计数

    while (!beginSet.empty() && !endSet.empty()) {
      // 总是从较小的集合开始扩展
      if (beginSet.size() > endSet.size()) {
        std::swap(beginSet, endSet);
      }

      std::unordered_set<std::string> tempSet;
      for (auto word : beginSet) {
        for (int i = 0; i < word.length(); ++i) {
          char originalChar = word[i];

          // 尝试改变当前单词的每一个字母
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;

            // 如果在另一端找到了单词，表示找到了路径
            if (endSet.find(word) != endSet.end()) {
              return step + 1;
            }

            // 如果单词在字典中，则加入到下一轮搜索
            if (wordSet.find(word) != wordSet.end()) {
              tempSet.insert(word);
              wordSet.erase(word);  // 从字典中移除，避免重复搜索
            }
          }

          word[i] = originalChar;  // 恢复原单词
        }
      }

      // 更新开始集合为下一轮搜索的集合
      beginSet = tempSet;
      ++step;  // 增加步数
    }

    return 0;  // 未找到有效路径
  }
};