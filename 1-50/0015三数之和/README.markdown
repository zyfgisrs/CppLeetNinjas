## 双指针法
解决“三数之和”问题的，目标是找出数组中所有能够使三个数加和为零的唯一组合。代码主要利用了排序和双指针技术来解决问题。下面是这个解决方案的要点：

### 1. 排序

首先，数组`nums`被排序。这有助于我们跳过重复值，并且使我们能够有效地使用双指针方法。

```cpp
std::sort(nums.begin(), nums.end());
```

### 2. 初始化结果数组

一个名为`result`的二维向量用于存储满足条件的三个数的组合。

```cpp
std::vector<std::vector<int>> result;
```

### 3. 主循环

一个外层的for循环用于遍历数组，其中`i`是当前选定的第一个数字。

```cpp
for (int i = 0; i < nums.size() - 2; ++i) {
  // ...
}
```

### 4. 跳过重复项

如果数组中有重复的元素，我们跳过它们以避免重复的组合。

```cpp
if (i > 0 && nums[i - 1] == nums[i]) continue;
```

### 5. 早停条件

如果当前数字`nums[i]`大于0，那么在这个排序数组里再也找不到三个数使得它们的和为0，所以可以直接跳出循环。

```cpp
if (nums[i] > 0) break;
```

### 6. 双指针技术

两个指针`left`和`right`分别初始化为`i+1`和数组的最后一个元素。这两个指针用于在数组的剩余部分中寻找两个数，使它们与`nums[i]`的和为零。

```cpp
int left = i + 1;
int right = nums.size() - 1;
```

### 7. 内部循环

内部的`while`循环用于移动`left`和`right`指针，直到找到一个有效的组合或者两个指针相遇。

```cpp
while (left < right) {
  // ...
}
```

### 8. 更新双指针

根据`sum`和0的比较，`left`和`right`指针相应地向内移动。

```cpp
if (sum < 0) {
  ++left;
} else if (sum > 0) {
  --right;
}
```

### 9. 存储和跳过重复的组合

如果找到一个和为0的组合，我们存储它并更新`left`和`right`指针以跳过任何重复的组合。

```cpp
result.push_back({nums[i], nums[left], nums[right]});
while (left < right && nums[left] == nums[left + 1]) ++left;
while (left < right && nums[right] == nums[right - 1]) --right;
++left;
--right;
```

这样，通过排序和双指针技术，该方法能高效地找到数组中所有和为0的唯一三元组。

## 哈希表（效率较低）
使用哈希表方法来解决“三数之和”问题，目标是找出数组中所有能够使三个数加和为零的唯一组合，主要难点在于去除重复的组合。在这里我将三元组排序并转为字符串并配合set容器进行去重。下面是代码的主要要点：

### 1. 初始化数据结构

- `num_count`（一个 `unordered_map`）用于存储数组中每个数字出现的次数。
- `result`（一个二维向量）用于存储满足条件的三个数的组合。
- `unique_triplets`（一个 `unordered_set`）用于存储唯一的三元组，以防止重复。

```cpp
std::unordered_map<int, int> num_count;
std::vector<std::vector<int>> result;
std::unordered_set<std::string> unique_triplets;
```

### 2. 统计数字频率

遍历整个数组，统计每个数字出现的次数。

```cpp
for (auto num : nums) {
  ++num_count[num];
}
```

### 3. 外层循环

外层循环遍历哈希表中的每个键值对，其中 `i->first` 是数字，`i->second` 是该数字出现的次数。

```cpp
for (auto i = num_count.begin(); i != num_count.end(); ++i) {
  // ...
}
```

### 4. 更新次数并检查有效性

在每一次循环迭代中，我们使用一次当前数字（通过减少 `i->second`）。

```cpp
--i->second;
```

### 5. 内层循环

内层循环也遍历哈希表中的每个键值对，与外层循环相似。

```cpp
for (auto j = i; j != num_count.end(); ++j) {
  // ...
}
```

### 6. 计算两数之和

我们计算两数之和（`two_sum`），并找出需要的第三个数字（`third_num`）。

```cpp
int two_sum = i->first + j->first;
int third_num = -two_sum;
```

### 7. 检查第三个数字

我们检查第三个数字是否存在以及是否还有剩余。

```cpp
if (num_count.find(third_num) != num_count.end() && num_count[third_num] > 0) {
  // ...
}
```

### 8. 存储和跳过重复的组合

如果找到一个和为0的组合，我们存储它并更新哈希表和集合以跳过任何重复的组合。

```cpp
std::vector<int> triplet = {i->first, j->first, third_num};
std::string key = std::to_string(triplet[0]) + "," + std::to_string(triplet[1]) + "," + std::to_string(triplet[2]);
if (unique_triplets.find(key) == unique_triplets.end()) {
  unique_triplets.insert(key);
  result.push_back(triplet);
}
```

### 9. 回复数字的次数

在每一次内外循环迭代结束后，我们都会回复原本减少的次数。

```cpp
++j->second;
++i->second;
```

通过以上9个步骤，代码能够有效地找出数组中所有和为0的唯一三元组。
