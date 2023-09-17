#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  using NumType = int;
  using CountType = int;

 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::unordered_map<NumType, CountType> num_to_count_map;
    std::unordered_set<std::string> unique_triplets;
    // Count the number of occurrences of each number
    for (const auto& num : nums) {
      num_to_count_map[num]++;
    }

    for (auto i = num_to_count_map.begin(); i != num_to_count_map.end(); ++i) {
      --i->second;  // Decrement the count of the current number

      for (auto j = i; j != num_to_count_map.end(); ++j) {
        if (j->second == 0) continue;
        // Skip if the count of the current number is zero
        --j->second;  // Decrement the count of the current number
        int two_sum = i->first + j->second;
        int third_num = -two_sum;  // Calculate the third number
        if (num_to_count_map.find(third_num) != num_to_count_map.end() &&
            num_to_count_map[third_num] > 0) {
          // If the third number exists and its count is greater than zero
          std::vector<int> triplet = {i->first, j->first, third_num};
          std::sort(triplet.begin(), triplet.end());  // Sort the triplet
          // Check if the triplet has been added to the result
          std::string key = std::to_string(triplet[0]) + " " +
                            std::to_string(triplet[1]) + " " +
                            std::to_string(triplet[2]);
          if (unique_triplets.find(key) == unique_triplets.end()) {
            // If the triplet has not been added to the result
            unique_triplets.insert(key);
            result.push_back(triplet);
          }
        }
        ++j->second;
        // Restore the count of the current number
      }
      ++i->second;
      // Restore the count of the current number
    }
    return result;
  }
};