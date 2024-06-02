#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    // 确保nums1是较短的数组
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m, halfLen = (m + n + 1) / 2;
    while (left < right) {
      int i = left + (right - left) / 2;
      int j = halfLen - i;
      if (nums1[i] < nums2[j - 1]) {
        left = i + 1;
      } else {
        right = i;
      }
    }

    int i = left;
    int j = halfLen - left;

    int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
    int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
    int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
    int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

    if ((m + n) % 2 == 1) {
      return std::max(nums1LeftMax, nums2LeftMax);
    } else {
      return (std::max(nums1LeftMax, nums2LeftMax) +
              std::min(nums1RightMin, nums2RightMin)) /
             2.0;
    }
  }
};
