#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(std::string path) {
    std::stringstream ss(path);
    std::string curr;
    std::vector<std::string> st;

    while (std::getline(ss, curr, '/')) {
      if (curr == "" || curr == ".") continue;
      if (curr == "..") {
        if (!st.empty()) {
          st.pop_back();
        }
      } else {
        st.push_back(curr);
      }
    }

    std::string result = "/";
    for (int i = 0; i < st.size(); i++) {
      result += st[i];
      if (i < st.size() - 1) {
        result += "/";
      }
    }
    return result;
  }
};