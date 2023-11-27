#include <string>
#include <vector>

class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    int n = s.size();
    if (numRows == 1 || n <= numRows) {
      return s;
    }

    std::vector<std::string> rows(numRows);
    bool goDown = false;
    int curr = 0;

    for (int i = 0; i < n; i++) {
      rows[curr].push_back(s[i]);
      if (curr == 0 || curr == numRows - 1) {
        goDown = !goDown;
      }

      curr += goDown ? 1 : -1;
    }
    std::string ans;
    for (std::string& str : rows) {
      ans += str;
    }

    return ans;
  }
};