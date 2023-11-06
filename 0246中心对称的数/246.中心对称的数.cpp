#include <string>

class Solution {
 public:
  bool isStrobogrammatic(std::string num) {
    std::string temp = strobogrammatic(num);
    for (int i = 0; i < num.size(); ++i) {
      if (temp[i] != num[i]) {
        return false;
      }
    }
    return true;
  }

 private:
  std::string strobogrammatic(std::string& num) {
    std::string newNum;
    for (int i = num.size() - 1; i >= 0; --i) {
      char c = num[i];
      if (c == '2' || c == '3' || c == '4' || c == '5' || c == '7') {
        newNum.push_back('a');
      } else if (c == '6') {
        newNum.push_back('9');
      } else if (c == '9') {
        newNum.push_back('6');
      } else {
        newNum.push_back(c);
      }
    }
    return newNum;
  }
};