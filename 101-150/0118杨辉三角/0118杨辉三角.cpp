#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
      std::vector<int> vec(i + 1, 1);

      for (int j = 1; j < i; j++) {
        vec[j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
      ans.push_back(vec);
    }
    return ans;
  }
};