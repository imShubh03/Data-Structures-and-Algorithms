#include <bits/stdc++.h>
using namespace std;

// Function to calculate the time required for all oranges to rot
int orangesRotting(vector<vector<int>> &grid, int m, int n) {
    // Declare a queue to store {{row, col}, time}
    queue<pair<pair<int, int>, int>> q;  
    int vis[m][n]; // Visited array to keep track of rotted oranges

    // Initial configuration
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                // Push the initial rotten oranges with time 0
                q.push({{i, j}, 0});
                vis[i][j] = 2; // Mark as visited
            } else {
                vis[i][j] = 0; // Not visited
            }
        }
    }

    int time = 0; // To keep track of the maximum time
    int drow[] = {-1, 0, 1, 0}; // Row direction changes for 4 directions
    int dcol[] = {0, 1, 0, -1}; // Column direction changes for 4 directions

    // BFS traversal to rot adjacent fresh oranges
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int tm = q.front().second; // Current time step
        time = max(time, tm); // Update the time
        q.pop();

        // Traverse the adjacent neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // Check if the new cell is within bounds and is a fresh orange
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                // Mark the orange as rotten
                q.push({{nrow, ncol}, tm + 1});
                vis[nrow][ncol] = 2;
                grid[nrow][ncol] = 2; // Update the grid as well
            }
        }
    }

    // Check if there are still fresh oranges left
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1; // If a fresh orange is found, return -1
            }
        }
    }

    return time; // Return the time for all oranges to rot
}

int main() {
    int m, n; // Number of rows and columns
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = orangesRotting(grid, m, n);
    cout << ans << endl;

    return 0;
}
