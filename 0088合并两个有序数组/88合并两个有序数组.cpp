#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int index1 = m - 1, index2 = n - 1, mergeIndex = m + n - 1;
    while (index2 >= 0) {
      if (index1 >= 0 && nums1[index1] > nums2[index2]) {
        nums1[mergeIndex--] = nums1[index1--];
      } else {
        nums1[mergeIndex--] = nums2[index2--];
      }
    }
  }
};