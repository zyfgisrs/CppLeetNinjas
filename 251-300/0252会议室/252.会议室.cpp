#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return true;
    }

    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
              });

    for (int i = 0, j = 1; i < intervals.size() - 1; i++, j++) {
      if (intervals[i][1] > intervals[j][0]) {
        return false;
      }
    }

    return true;
  }
};