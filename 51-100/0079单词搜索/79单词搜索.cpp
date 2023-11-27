#include <string>
#include <vector>

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    bool result = false;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          result |= dfs(word, 1, i, j, board);
        }
      }
    }
    return result;
  }

  bool dfs(std::string& word, int index, int row, int col,
           std::vector<std::vector<char>>& board) {
    if (index == word.size()) {
      return true;
    }

    int m = board.size();
    int n = board[0].size();
    char target = word[index];

    // 保存当前字符，并暂时将其标记为已访问（例如，使用 '0'）
    char temp = board[row][col];
    board[row][col] = '0';

    // 向上搜索
    if (row - 1 >= 0 && board[row - 1][col] == target) {
      if (dfs(word, index + 1, row - 1, col, board)) return true;
    }

    // 向下搜索
    if (row + 1 < m && board[row + 1][col] == target) {
      if (dfs(word, index + 1, row + 1, col, board)) return true;
    }

    // 向右搜索
    if (col + 1 < n && board[row][col + 1] == target) {
      if (dfs(word, index + 1, row, col + 1, board)) return true;
    }

    // 向左搜索
    if (col - 1 >= 0 && board[row][col - 1] == target) {
      if (dfs(word, index + 1, row, col - 1, board)) return true;
    }

    // 恢复当前字符
    board[row][col] = temp;

    return false;
  }
};