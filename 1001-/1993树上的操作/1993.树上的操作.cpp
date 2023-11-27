/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start

#include <unordered_set>
#include <vector>
class LockingTree {
 private:
  std::vector<int> cache;
  std::vector<int> parent;

 public:
  LockingTree(std::vector<int> &parent) {
    std::vector<int> vec(parent.size());
    cache = vec;
    this->parent = parent;
  }

  bool isChildLocked(int k) {
    bool result = false;
    for (int i = 0; i < parent.size(); i++) {
      if (parent[i] == k) {
        if (cache[i] != 0) {
          result = true;
          cache[i] = 0;
        }
        result = isChildLocked(i) || result;
      }
    }
    return result;
  }

  bool lock(int num, int user) {
    if (cache[num] != 0) {
      return false;
    } else {
      cache[num] = user;
      return true;
    }
  }

  bool unlock(int num, int user) {
    if (cache[num] == 0 || cache[num] != user) {
      return false;
    } else {
      cache[num] = 0;
      return true;
    }
  }

  bool upgrade(int num, int user) {
    // 检查此节点有没有锁
    if (cache[num] != 0) {
      return false;
    }

    // 检查有没有祖先节点上锁
    int ancestorValue = parent[num];  // 祖先的数值

    while (ancestorValue != -1) {
      if (cache[ancestorValue] != 0) {
        return false;
      }
      ancestorValue = parent[ancestorValue];
    };

    // 判断是否有上锁的子节点，并将可能需要的解锁的结点放到一个集合中
    bool haschildLocked = isChildLocked(num);
    if (haschildLocked) cache[num] = user;
    return haschildLocked;
  }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end
