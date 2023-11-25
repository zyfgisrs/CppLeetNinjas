#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
      int width = right - left;
      int h = std::min(height[left], height[right]);
      max_area = std::max(max_area, h * width);

      height[left] < height[right] ? left++ : right--;
    }

    return max_area;
  }
};