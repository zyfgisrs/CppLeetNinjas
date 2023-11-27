#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isStrobogrammatic(std::string num) {
    // 使用哈希表存储中心对称的数字对
    std::unordered_map<char, char> strobogrammatic_pairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    int left = 0;
    int right = num.size() - 1;

    while (left <= right) {
      // 如果字符不在我们的哈希表中，或者右侧字符不等于左侧字符对应的中心对称字符，则返回false
      if (strobogrammatic_pairs.find(num[left]) ==
              strobogrammatic_pairs.end() ||
          strobogrammatic_pairs[num[left]] != num[right]) {
        return false;
      }
      ++left;
      --right;
    }

    return true;
  }
};