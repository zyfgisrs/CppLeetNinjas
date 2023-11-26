#include <string>
#include <vector>

class Solution {
 public:
  std::string intToRoman(int num) {
    static const std::vector<std::pair<int, std::string>> valueSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    std::string roman = "";
    for (const auto& [value, str] : valueSymbols) {
      while (num >= value) {
        num -= value;
        roman += str;
      }
    }
    return roman;
  }
};