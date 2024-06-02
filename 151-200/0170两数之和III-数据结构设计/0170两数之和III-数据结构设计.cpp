#include <unordered_map>

class TwoSum {
 public:
  TwoSum() {}

  void add(int number) { nums[number]++; }

  bool find(int value) {
    for (const auto& pair : nums) {
      long long complement = static_cast<long long>(value) - pair.first;
      if (complement == pair.first) {
        // 如果需要的数与当前数相同，检查是否有至少两个这样的数
        if (pair.second > 1) return true;
      } else {
        // 检查哈希表中是否存在配对的数
        if (nums.count(complement)) return true;
      }
    }
    return false;
  }

 private:
  std::unordered_map<int, int> nums;  // 存储每个数及其出现次数
};