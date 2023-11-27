#include <algorithm>
#include <vector>


class Solution {
 public:
  int maximumGap(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int minVal = *std::min_element(nums.begin(), nums.end());
    int maxVal = *std::max_element(nums.begin(), nums.end());
    int bucketInterval = std::max(1, (maxVal - minVal) / (n - 1));
    int bucketCount = (maxVal - minVal) / bucketInterval + 1;

    std::vector<std::pair<int, int>> buckets(bucketCount, {-1, -1});

    // 分配数字到桶中
    for (int num : nums) {
      int idx = (num - minVal) / bucketInterval;
      if (buckets[idx].first == -1) {
        buckets[idx] = {num, num};
      } else {
        buckets[idx].first = std::min(buckets[idx].first, num);
        buckets[idx].second = std::max(buckets[idx].second, num);
      }
    }

    // 计算最大间距
    int maxGap = 0, prevMax = -1;
    for (auto& bucket : buckets) {
      if (bucket.first == -1) continue;
      if (prevMax != -1) {
        maxGap = std::max(maxGap, bucket.first - prevMax);
      }
      prevMax = bucket.second;
    }

    return maxGap;
  }
};