#include <string>

using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    reverseStr(0, n - 1, s);
    reverseStr(n, s.length() - 1, s);
    reverseStr(0, s.length() - 1, s);
    return s;
  }

 private:
  void reverseStr(int left, int right, std::string& s) {
    while (left < right) {
      std::swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};