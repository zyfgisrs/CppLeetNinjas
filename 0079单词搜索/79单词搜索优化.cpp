#include <string>
#include <vector>

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0] && dfs(word, 1, m, n, i, j, board)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(std::string& word, int index, int m, int n, int row, int col,
           std::vector<std::vector<char>>& board) {
    if (index == word.size()) {
      return true;
    }

    char target = word[index];
    char temp = board[row][col];
    board[row][col] = '0';

    static const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    for (const auto& direction : directions) {
      int newRow = row + direction.first, newCol = col + direction.second;
      if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
          board[newRow][newCol] == target) {
        if (dfs(word, index + 1, m, n, newRow, newCol, board)) {
          return true;
        }
      }
    }

    // 恢复当前字符
    board[row][col] = temp;

    return false;
  }
};