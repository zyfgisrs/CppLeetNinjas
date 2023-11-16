
#include <iostream>
#include <vector>

class UnionFind {
 private:
  std::vector<int> parent;

 public:
  UnionFind(int size) {
    parent.resize(size);
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);  // 路径压缩
  }

  void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      parent[rootX] = rootY;  // 合并两个集合
    }
  }
};

int main() {
  UnionFind uf(6);

  uf.unionSets(1, 2);
  uf.unionSets(2, 3);
  uf.unionSets(3, 4);

  for (int i = 0; i < 6; i++) {
    std::cout << "Element " << i << " is in set: " << uf.find(i) << std::endl;
  }

  return 0;
}