## 解决leetcode18. 4数之和问题

### 去重策略
在处理这种需要找到多个唯一组合的问题时，去重是一个关键步骤。在本解决方案中，去重的思想贯穿始终，具体体现在以下几个方面：

1. **排序**: 数组首先被排序，这样相同的元素会被放在一起，便于后续去重。

2. **跳过重复的外层元素**: 在两层外循环中（控制变量分别为 `i` 和 `j`），如果遇到与前一个元素相同的元素，就直接跳过。这避免了生成重复的四元组。

    ```cpp
    if (i > 0 && nums[i - 1] == nums[i]) continue;
    if (j > i + 1 && nums[j - 1] == nums[j]) continue;
    ```

3. **跳过重复的内层元素**: 在内层双指针循环（控制变量为 `left` 和 `right`）中，如果找到了一个有效的四元组，会将 `left` 和 `right` 移至下一个不同的元素。

    ```cpp
    while (left < right && nums[left] == nums[left + 1]) ++left;
    while (right > left && nums[right] == nums[right - 1]) --right;
    ```

### 算法流程
1. 预处理数组，进行排序。
2. 两层循环遍历 `i` 和 `j`。
3. 在每一对 `(i, j)` 的基础上，使用双指针 `left` 和 `right` 来查找满足条件的四元组。

### 辅助函数
`findFourSum` 是一个私有辅助函数，专门用于处理在给定的 `i` 和 `j` 下，找到所有满足条件的四元组。这种模块化的设计使代码更为清晰和可维护。

### 复杂度
- 时间复杂度：\(O(n^3)\)
- 空间复杂度：\(O(1)\)（不考虑输出的空间）

通过嵌套循环和双指针法，以及精心设计的去重策略，这个算法有效地解决了4数之和问题。