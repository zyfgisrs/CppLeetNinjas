#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<std::string>& words) {
    int n = words.size();
    std::vector<int> mask(n, 0);  // 用于存储每个单词对应的二进制表示
    std::vector<int> lens(n, 0);  // 存储每个单词的长度

    // 构建单词的位掩码表示
    for (int i = 0; i < n; ++i) {
      for (char ch : words[i]) {
        mask[i] |= 1 << (ch - 'a');
      }
      lens[i] = words[i].size();
    }

    int res = 0;
    // 比较单词对是否有公共字母
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (!(mask[i] & mask[j])) {  // 没有公共字母
          res = std::max(res, int(lens[i] * lens[j]));
        }
      }
    }

    return res;
  }
};