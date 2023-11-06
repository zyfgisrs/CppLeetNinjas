#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool sequenceReconstruction(std::vector<int>& nums,
                              std::vector<std::vector<int>>& sequences) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::unordered_map<int, int> inDegree;

    for (int num : nums) {
      inDegree[num] = 0;
    }

    for (std::vector<int> vec : sequences) {
      for (int i = 0; i < vec.size() - 1; i++) {
        if (graph[vec[i]].insert(vec[i + 1]).second) {
          inDegree[vec[i + 1]]++;
        }
      }
    }

    std::queue<int> q;
    for (auto& [num, degree] : inDegree) {
      if (degree == 0) {
        q.push(num);
      }
    }

    std::vector<int> topoOrder;
    while (!q.empty()) {
      if (q.size() > 1) {
        return false;
      }

      int cur = q.front();
      q.pop();
      topoOrder.push_back(cur);

      for (int num : graph[cur]) {
        if (--inDegree[num] == 0) {
          q.push(num);
        }
      }
    }

    // 对于两个vector使用==进行比较，是比较它们的元素是否相等
    return topoOrder == nums;
  }
};