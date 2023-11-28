#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
  int compareVersion(std::string version1, std::string version2) {
    std::vector<int> versionParts1 = parseVersion(version1);
    std::vector<int> versionParts2 = parseVersion(version2);
    int maxLength = std::max(versionParts1.size(), versionParts2.size());

    for (int i = 0; i < maxLength; i++) {
      // 比较时动态处理
      int part1 = i < versionParts1.size() ? versionParts1[i] : 0;
      int part2 = i < versionParts2.size() ? versionParts2[i] : 0;
      if (part1 < part2) return -1;
      if (part1 > part2) return 1;
    }
    return 0;
  }

 private:
  std::vector<int> parseVersion(const std::string& version) {
    std::stringstream versionStream(version);
    std::vector<int> parts;
    std::string part;
    while (std::getline(versionStream, part, '.')) {
      // stoi自动忽略前导零
      parts.push_back(std::stoi(part));
    }
    return parts;
  }
};