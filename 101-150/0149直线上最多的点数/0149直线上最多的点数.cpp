#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  struct Slope {
    int dx, dy;

    Slope(int x, int y) {
      int common = gcd(abs(x), abs(y));
      dx = x / common;
      dy = y / common;
      // 确保斜率的唯一性
      if (dy < 0 || (dy == 0 && dx < 0)) {
        dx = -dx;
        dy = -dy;
      }
    }

    bool operator==(const Slope &other) const {
      return dx == other.dx && dy == other.dy;
    }

    struct Hash {  // 生成Slope对象的Hash函数
      size_t operator()(const Slope &s) const {
        return hash<int>()(s.dx) ^ hash<int>()(s.dy);
      }
    };

    static int gcd(int x, int y) {
      while (y) {
        x %= y;
        swap(x, y);
      }
      return x;
    }
  };

  int maxPoints(vector<vector<int>> &points) {
    if (points.size() <= 2) return points.size();
    int res = 2;
    for (int i = 0; i < points.size() - 1; i++) {
      unordered_map<Slope, int, Slope::Hash> mp;
      for (int j = i + 1; j < points.size(); j++) {
        Slope slope(points[j][0] - points[i][0], points[j][1] - points[i][1]);
        mp[slope]++;
        res = max(res, mp[slope] + 1);
      }
    }
    return res;
  }
};
