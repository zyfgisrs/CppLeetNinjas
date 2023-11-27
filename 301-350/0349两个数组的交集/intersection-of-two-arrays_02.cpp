#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    std::vector<int> result;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        ++i;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {  // nums1[i] == nums2[j]
        if (result.empty() || result.back() != nums1[i]) {
          result.push_back(nums1[i]);
        }
        ++i;
        ++j;
      }
    }

    return result;
  }
};