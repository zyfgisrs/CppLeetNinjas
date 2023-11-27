#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(std::string path) {
    std::stringstream ss(path);
    std::string curr;
    std::vector<std::string> vec;

    while (std::getline(ss, curr, '/')) {
      if (curr == "" || curr == ".") continue;
      if (curr == "..") {
        if (!vec.empty()) vec.pop_back();
      } else {
        vec.push_back(curr);
      }
    }

    std::string str = "/";
    int s = vec.size();
    for (int i = 0; i < s; i++) {
      str += vec[i];
      if (i < s - 1) str += "/";
    }
    return str;
  }
};