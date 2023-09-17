#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  using SumType = int;
  using CountType = int;

 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    std::unordered_map<SumType, CountType> sum_to_count_map;
    int result = 0;
    // 计算 nums1 和 nums2 的所有可能和，并存储在哈希表中
    for (const int& value1 : nums1) {
      for (const int& value2 : nums2) {
        int sum = value1 + value2;
        sum_to_count_map[sum]++;
      }
    }
    // 计算 nums3 和 nums4 的所有可能和，并查看哈希表中是否存在相反数
    for (const int& value3 : nums3) {
      for (const int& value4 : nums4) {
        int sum = value3 + value4;
        // 如果哈希表中存在相反数，则将其对应的计数器累加到结果中
        if (sum_to_count_map.find(-sum) != sum_to_count_map.end()) {
          result += sum_to_count_map[-sum];
        }
      }
    }
    return result;
  }
};