#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> repeatedSequences;
    if (s.size() <= 10) {
      return repeatedSequences;
    }

    static const std::unordered_map<char, int> nucleotideToInt = {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int dnaHash = 0;
    int count[1048576] = {0};  // 4的10次方

    for (int i = 0; i < 9; ++i) {
      dnaHash = (dnaHash << 2) | nucleotideToInt.at(s[i]);
    }

    for (int i = 9; i < s.size(); ++i) {
      // 0xfffff为二进制1111 1111 1111 1111 1111
      dnaHash = ((dnaHash << 2) | nucleotideToInt.at(s[i])) & 0xfffff;
      if (count[dnaHash] == 1) {
        repeatedSequences.push_back(s.substr(i - 9, 10));
      }
      count[dnaHash]++;
    }

    return repeatedSequences;
  }
};