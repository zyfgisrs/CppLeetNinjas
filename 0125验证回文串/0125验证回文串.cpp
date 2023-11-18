#include <string>


class Solution {
 public:
  bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      // Increment left index if the character is not alphanumeric
      while (left < right && !std::isalnum(s[left])) {
        left++;
      }

      // Decrement right index if the character is not alphanumeric
      while (left < right && !std::isalnum(s[right])) {
        right--;
      }

      // Check if the characters are equal after converting to lowercase
      if (std::tolower(s[left]) != std::tolower(s[right])) {
        return false;
      }

      left++;
      right--;
    }
    return true;
  }
};