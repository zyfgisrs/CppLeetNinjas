#include <unordered_set>

class Solution {
 public:
  bool isHappy(int n) {
    // Input validation
    if (n <= 0) {
      return false;
    }

    // Create a hash set to track numbers we've seen before
    std::unordered_set<int> seenNumbers;

    while (n != 1) {
      // Calculate the sum of squares of the digits
      int new_n = sumOfSquareDigits(n);

      // Check if this number has been seen before
      if (seenNumbers.find(new_n) != seenNumbers.end()) {
        return false;
      } else {
        seenNumbers.insert(new_n);
      }

      n = new_n;
    }
    return true;
  }

 private:
  // Helper function to calculate sum of squares of digits
  int sumOfSquareDigits(int num) {
    int sum = 0;
    while (num != 0) {
      int digit = num % 10;
      sum += digit * digit;
      num /= 10;
    }
    return sum;
  }
};
