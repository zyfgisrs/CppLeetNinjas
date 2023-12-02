#include <stdexcept>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      std::swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int minIndex = 0, maxIndex = m;

    while (minIndex <= maxIndex) {
      int i = (minIndex + maxIndex) / 2;
      int j = (m + n + 1) / 2 - i;

      int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
      int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
      int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
      int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

      if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
        return getMedian(nums1LeftMax, nums1RightMin, nums2LeftMax,
                         nums2RightMin, m, n);
      } else if (nums1LeftMax > nums2RightMin) {
        maxIndex = i - 1;
      } else {
        minIndex = i + 1;
      }
    }

    throw std::invalid_argument(
        "Input arrays are not valid for median calculation.");
  }

 private:
  double getMedian(int nums1LeftMax, int nums1RightMin, int nums2LeftMax,
                   int nums2RightMin, int m, int n) {
    if ((m + n) % 2 == 0) {
      return (std::max(nums1LeftMax, nums2LeftMax) +
              std::min(nums1RightMin, nums2RightMin)) /
             2.0;
    } else {
      return std::max(nums1LeftMax, nums2LeftMax);
    }
  }
};
