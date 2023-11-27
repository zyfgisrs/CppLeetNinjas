#include <unordered_set>
#include <vector>

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::unordered_set<int> iset;
    std::unordered_set<int> jset;

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          iset.insert(i);
          jset.insert(j);
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (iset.find(i) != iset.end() || jset.find(j) != jset.end()) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};