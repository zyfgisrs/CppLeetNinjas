#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    // 对所有边界上的 'O' 执行深度优先搜索
    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0, m, n);
      dfs(board, i, n - 1, m, n);
    }
    for (int i = 1; i < n - 1; ++i) {
      dfs(board, 0, i, m, n);
      dfs(board, m - 1, i, m, n);
    }

    // 遍历整个矩阵
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == 'E') board[i][j] = 'O';
      }
    }
  }

 private:
  void dfs(std::vector<std::vector<char>>& board, int x, int y, int m, int n) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'E';
    dfs(board, x - 1, y, m, n);
    dfs(board, x + 1, y, m, n);
    dfs(board, x, y - 1, m, n);
    dfs(board, x, y + 1, m, n);
  }
};
