#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int m, int n, int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis) {
        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(m, n, nrow, ncol, board, vis);
            }
        }
    }

public:
    void solve(int m, int n, vector<vector<char>> &board) {
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Traverse first and last rows
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(m, n, 0, j, board, vis);
            }
            if (!vis[m - 1][j] && board[m - 1][j] == 'O') {
                dfs(m, n, m - 1, j, board, vis);
            }
        }

        // Traverse first and last columns
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(m, n, i, 0, board, vis);
            }
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                dfs(m, n, i, n - 1, board, vis);
            }
        }

        // Replace unvisited 'O' with 'X' and revert visited 'O' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    Solution sol.
    sol.solve(m, n, board);

    for (const auto &row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
