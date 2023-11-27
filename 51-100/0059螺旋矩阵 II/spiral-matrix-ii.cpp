#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    int num = 1;

    for (int layer = 0; layer < (n + 1) / 2; ++layer) {
      fillLayer(ans, layer, n, num);
    }

    return ans;
  }

 private:
  void fillLayer(std::vector<std::vector<int>>& matrix, int layer, int n,
                 int& num) {
    // Fill top row
    for (int x = layer; x < n - layer; ++x) {
      matrix[layer][x] = num++;
    }
    // Fill right column
    for (int y = layer + 1; y < n - layer; ++y) {
      matrix[y][n - layer - 1] = num++;
    }
    // Fill bottom row
    for (int x = n - layer - 2; x >= layer; --x) {
      matrix[n - layer - 1][x] = num++;
    }
    // Fill left column
    for (int y = n - layer - 2; y > layer; --y) {
      matrix[y][layer] = num++;
    }
  }
};

int main() {
  Solution s;
  auto res = s.generateMatrix(3);
  for (const auto& vec : res) {
    for (const auto& value : vec) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
}