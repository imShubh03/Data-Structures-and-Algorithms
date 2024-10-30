#include <bits/stdc++.h>
using namespace std;

/*recursion
class Solution {
    public:
    int solve(int i, int j, vector<vector<int>> &grid) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;

        int up =  solve(i - 1, j, grid);
        int left =  solve(i, j - 1, grid);

        return grid[i][j] + min(up, left);
    }
    
    int minPathSum(int m, int n, vector<vector<int>> &grid) {
        return solve(m - 1, n - 1, grid);
    }
};
*/

/*memoisaton
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // Base case: if at the top-left corner
        if (i == 0 && j == 0) return grid[0][0];
        // Out of bounds
        if (i < 0 || j < 0) return INT_MAX;

        // Return memoized result if already calculated
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls for up and left paths
        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);

        // Store the result in dp with the current cell's value added
        dp[i][j] = grid[i][j] + min(up, left);
        return dp[i][j];
    }

    int minPathSum(int m, int n, vector<vector<int>>& grid) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};
*/

/*
class Solution {
public:
    int minPathSum(int m, int n, vector<vector<int>> &grid) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j]; // Starting point
                } else {
                    int up = INT_MAX, left = INT_MAX;

                    if(i > 0) up = dp[i - 1][j]; // From the top
                    if(j > 0) left = dp[i][j - 1]; // From the left

                    dp[i][j] = grid[i][j] + min(up, left); // Current cell value + min path sum
                }
            }
        }

        return dp[m - 1][n - 1]; // Return the result from the bottom-right cell
    }
};
*/

class Solution {
public:
    int minPathSum(int m, int n, vector<vector<int>> &grid) {
        vector<int> prev(n, 0); // Previous row
        vector<int> curr(n, 0); // Current row

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j]; // Starting point
                } else {
                    int up = INT_MAX, left = INT_MAX;

                    if(i > 0) up = prev[j]; // From the top
                    if(j > 0) left = curr[j - 1]; // From the left

                    curr[j] = grid[i][j] + min(up, left); // Current cell value + min path sum
                }
            }
            prev = curr; // Move to the next row
        }

        return curr[n - 1]; // Return the result from the last computed current row
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int ans = sol.minPathSum(m, n, grid);
    cout << ans;

    return 0;
}