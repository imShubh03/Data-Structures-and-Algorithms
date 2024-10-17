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


/*
void dfs(int row, int col, vector<vector<int>>& vis, int** arr, int n, int m) {
    // Direction vectors for moving in 4 directions
    int delRow[] = {-1, 1, 0, 0}; // Up, Down
    int delCol[] = {0, 0, -1, 1}; // Left, Right

    // Mark current cell as visited
    vis[row][col] = 1;

    // Traverse all 4 directions
    for (int i = 0; i < 4; i++) {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        // Check if the new cell is within bounds and is a land cell that hasn't been visited
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            !vis[newRow][newCol] && arr[newRow][newCol] == 1) {
            dfs(newRow, newCol, vis, arr, n, m);
        }
    }
}

int getTotalIslands(int** arr, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    // Traverse the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If the cell is land and not visited, perform DFS
            if (!vis[row][col] && arr[row][col] == 1) {
                dfs(row, col, vis, arr, n, m);
                cnt++; // Increment the count of islands
            }
        }
    }
    return cnt;
}

*/