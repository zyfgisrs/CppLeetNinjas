#include <unordered_map>
#include <vector>
using namespace std;

// leetcode two-sum
class Solution {
  using IndexType = int;
  using ValueType = int;

 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<ValueType, IndexType> value_to_index_map;
    for (int i = 0; i < nums.size(); i++) {
      ValueType complement = target - nums[i];
      if (value_to_index_map.find(complement) != value_to_index_map.end()) {
        return {i, value_to_index_map[target - nums[i]]};
      }
      value_to_index_map[nums[i]] = i;
    }
    return {};
  }
};