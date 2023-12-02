#include <vector>

// 差分数组
class Solution {
 public:
  bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
    std::vector<int> passengerChange(1001, 0);

    for (const auto& trip : trips) {
      int numPassengers = trip[0];
      int startLocation = trip[1];
      int endLocation = trip[2];

      passengerChange[startLocation] += numPassengers;
      passengerChange[endLocation] -= numPassengers;
    }

    int currentPassengers = 0;
    for (int passengersAtLocation : passengerChange) {
      currentPassengers += passengersAtLocation;
      if (currentPassengers > capacity) {
        return false;
      }
    }

    return true;
  }
};