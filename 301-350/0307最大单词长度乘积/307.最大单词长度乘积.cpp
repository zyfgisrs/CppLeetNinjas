
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

// 暴力解法，超时，不能通过
class Solution {
 public:
  int maxProduct(std::vector<std::string>& words) {
    int res = 0;
    for (int i = 0; i < words.size(); ++i) {
      std::string word = words[i];
      std::unordered_set<char> set;
      for (char ch : word) {
        set.insert(ch);
      }
      for (int j = i + 1; j < words.size(); j++) {
        std::string another = words[j];
        bool flag = true;
        for (char ch : another) {
          if (set.find(ch) != set.end()) {
            flag = false;
            continue;
          }
        }
        if (flag) res = std::max(res, int(word.size() * another.size()));
      }
    }
    return res;
  }
};