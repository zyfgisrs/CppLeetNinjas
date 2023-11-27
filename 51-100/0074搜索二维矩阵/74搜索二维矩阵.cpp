#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (matrix[mid][0] < target) {
        low = mid + 1;
      } else if (matrix[mid][0] > target) {
        high = mid;
      } else {
        return true;
      }
    }

    if (low == 0) return false;

    int row = low - 1;
    int left = 0, right = m - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[row][mid] == target) {
        return true;
      } else if (matrix[row][mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};