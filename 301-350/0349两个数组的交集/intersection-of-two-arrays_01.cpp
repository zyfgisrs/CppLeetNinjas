#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //创建一个unordered_set，将nums1中的元素放入其中，并去重
    std::unordered_set<int> numSet(nums1.begin(), nums2.end());
    //创建一个unordered_set，用于存放交集元素
    std::unordered_set<int> intersectionSet;

    for (const auto& value : nums2) {
      //如果nums2中的元素在numSet中存在，则将其放入intersectionSet中
      if (numSet.find(value) != numSet.end()) {
        intersectionSet.insert(value);
      }
    }
    //将unordered_set转换为vector
    return std::vector<int>(intersectionSet.begin(), intersectionSet.end());
  }
};