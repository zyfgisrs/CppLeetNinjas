#include <string>

class Solution {
 public:
  bool isOneEditDistance(std::string s, std::string t) {
    int m = s.size();
    int n = t.size();

    if (m > n) return isOneEditDistance(t, s);

    if (n - m > 1) return false;

    for (int i = 0; i < m; i++) {
      if (s[i] != t[i]) {
        if (m == n) return s.substr(i + 1) == t.substr(i + 1);
        return s.substr(i) == t.substr(i + 1);
      }
    }
    return m + 1 == n;
  }
};