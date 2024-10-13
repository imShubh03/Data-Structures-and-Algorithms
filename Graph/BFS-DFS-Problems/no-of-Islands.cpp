#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int m, int n) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int delrow[] = {-1, 0, 1, 0}; //(up, right, down, left)
        int delcol[] = {0, 1, 0, -1}; // (up, right, down, left)

        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = currRow + delrow[i];
                int ncol = currCol + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid, int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid, m, n);
                }
            }
        }
        return cnt;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int ans = sol.numIslands(grid, m, n);
    cout << ans;

    return 0;
}
