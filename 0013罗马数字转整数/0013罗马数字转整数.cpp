#include <string>
#include <unordered_map>

class Solution {
 public:
  int romanToInt(std::string s) {
    static std::unordered_map<std::string, int> valueSymbols = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
        {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
        {"V", 5},    {"IV", 4},   {"I", 1}};

    int curr = s.size() - 1;

    int total = 0;

    while (curr >= 0) {
      std::string towChar = curr >= 1 ? s.substr(curr - 1, 2) : "";
      if (valueSymbols.find(towChar) != valueSymbols.end()) {
        total += valueSymbols[towChar];
        curr -= 2;
        continue;
      }

      total += valueSymbols[s.substr(curr--, 1)];
    }

    return total;
  }
};