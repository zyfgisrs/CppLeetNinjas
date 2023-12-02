#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> successfulPairs(std::vector<int>& spells,
                                   std::vector<int>& potions,
                                   long long success) {
    std::sort(potions.begin(), potions.end());
    std::vector<int> result(spells.size());

    for (int i = 0; i < spells.size(); i++) {
      if ((long long)spells[i] * potions.front() >= success) {
        result[i] = spells.size();
        continue;
      }

      if ((long long)spells[i] * potions.back() < success) {
        result[i] = 0;
        continue;
      }

      int left = 0;
      int right = potions.size();

      while (left < right) {
        int mid = left + (right - left) / 2;
        if ((long long)spells[i] * potions[mid] < success) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      result[i] = potions.size() - left;
    }
    return result;
  }
};