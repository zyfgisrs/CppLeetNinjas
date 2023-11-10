#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string text = ",,,";
  std::stringstream ss(text);
  std::vector<std::string> tokens;
  std::string curr;

  while (std::getline(ss, curr, ',')) {
    tokens.push_back(curr);
  }

  std::cout << tokens.size() << std::endl;

  for (int i = 0; i < tokens.size(); i++) {
    std::cout << tokens[i] << std::endl;
  }
};