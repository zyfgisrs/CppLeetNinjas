#include <vector>

class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> row(rowIndex + 1, 1);  // 初始化为1

    // 从第二个元素开始计算直到倒数第二个元素（第一个和最后一个元素始终为1）
    for (int i = 1; i < rowIndex; ++i) {
      // 从后往前计算，这样可以确保计算当前元素时，前一个元素的值还没被更新
      for (int j = i; j > 0; --j) {
        row[j] += row[j - 1];
      }
    }

    return row;
  }
};
