#include <vector>

class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    // 从三角形的倒数第二行开始向上计算
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        // 更新当前位置的最小路径和
        triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }
    // 返回顶部位置的最小路径和
    return triangle[0][0];
  }
};