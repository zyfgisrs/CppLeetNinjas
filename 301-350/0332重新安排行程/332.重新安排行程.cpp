#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findItinerary(
      std::vector<std::vector<std::string>>& tickets) {
    std::vector<std::string> path;
    path.push_back("JFK");
    helper(tickets.size(), tickets, path, "JFK");
    return path;
  }

  void helper(int n, std::vector<std::vector<std::string>>& tickets,
              std::vector<std::string>& path, std::string current) {
    if (n == path.size() - 1) {
      return;
    }
    std::string end = "";
    int index;
    for (int i = 0; i < tickets.size(); ++i) {
      std::vector<std::string> ticket = tickets[i];
      if (ticket[0] == current) {
        std::string endtemp = ticket[1];
        if (isFront(end, endtemp)) {
          end = endtemp;
          index = i;
        }
      }
    }
    tickets.erase(tickets.begin() + index);
    path.push_back(end);
    helper(n, tickets, path, end);
  }

  bool isFront(std::string& temp, std::string& target) {
    if (temp == "") {
      return true;
    }
    for (int i = 0; i < temp.size(); ++i) {
      if (temp[i] < target[i]) {
        return false;
      } else if (temp[i] > target[i]) {
        return true;
      }
    }
    return true;
  }
};