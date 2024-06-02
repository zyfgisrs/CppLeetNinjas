#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::unordered_set<int>> graph;

    std::unordered_map<int, int> inDegree;

    int sum = 0;

    for (int i = 0; i < numCourses; i++) {
      inDegree[i] = 0;
    }

    for (std::vector<int> seq : prerequisites) {
      if (graph[seq[1]].insert(seq[0]).second) {
        inDegree[seq[0]]++;
      }
    }

    std::queue<int> q;
    for (auto& [num, degree] : inDegree) {
      if (degree == 0) {
        q.push(num);
      }
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      sum++;

      for (int next : graph[cur]) {
        if (--inDegree[next] == 0) {
          q.push(next);
        }
      }
    }
    return sum >= numCourses;
  }
};