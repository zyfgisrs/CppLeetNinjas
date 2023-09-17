#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    //使用双指针来原地交换字符
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    }
  }
};