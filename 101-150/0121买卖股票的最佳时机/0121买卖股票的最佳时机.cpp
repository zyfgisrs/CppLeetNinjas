#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
      minPrice = std::min(minPrice, prices[i]);
      maxProfit = std::max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
  }
};