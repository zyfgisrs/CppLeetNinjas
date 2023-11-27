class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || x % 10 == 0 && x != 0) {
      return false;
    }

    int reversedPart = 0;
    while (reversedPart < x) {
      reversedPart = reversedPart * 10 + x % 10;
      x /= 10;
    }

    return reversedPart == x || x == reversedPart / 10;
  }
};