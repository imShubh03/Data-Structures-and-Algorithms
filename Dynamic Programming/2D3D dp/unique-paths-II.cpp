#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& mat) {
        if (i == 0 && j == 0) {
            if (mat[i][j] == 0) return 1;
            else return 0; // Starting point with obstacle
        }
        if (i < 0 || j < 0 || mat[i][j] == 1) return 0; // Out of bounds or obstacle
        int up = solve(i - 1, j, mat);   // Move up
        int left = solve(i, j - 1, mat); // Move left

        return up + left;
    }
    
public:
    int uniquePathsWithObstacles(int m, int n, vector<vector<int>>& mat) {
        if (mat[0][0] == 1 || mat[m - 1][n - 1] == 1) return 0; // No path if start or end is blocked
        return solve(m - 1, n - 1, mat);
    }
};
*/

/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        // Base case: start point
        if (i == 0 && j == 0) {
            if (mat[i][j] == 1) return 0;
            return 1;
        }
        
        // Boundary and obstacle check
        if (i < 0 || j < 0 || mat[i][j] == 1) return 0;
        
        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = solve(i - 1, j, mat, dp);
        int left = solve(i, j - 1, mat, dp);

        // Store result in dp array
        dp[i][j] = left + up;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(int m, int n, vector<vector<int>> &mat) {
        if (mat[0][0] == 1 || mat[m - 1][n - 1] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, mat, dp);
    }
};
*/

/*tabulation
class Solution {
public:
    int uniquePathsWithObstacles(int m, int n, vector<vector<int>> &mat) {
        if (mat[0][0] == 1 || mat[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; // Start from the top-left corner

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dp[i][j] = 0; // No paths through obstacles
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j]; // Add paths from the upper cell
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1]; // Add paths from the left cell
                    }
                }
            }
        }

        return dp[m - 1][n - 1]; // Return paths to the bottom-right corner
    }
};
*/

//space optimsa
class Solution {
public:
    int uniquePathsWithObstacles(int m, int n, vector<vector<int>>& mat) {
        if (mat[0][0] == 1 || mat[m - 1][n - 1] == 1) return 0;

        vector<int> prev(n, 0);
        
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    curr[j] = 0; // No paths through obstacles
                } else {
                    if (i == 0 && j == 0) {
                        curr[j] = 1; // Starting point
                    } else {
                        int up = 0, left = 0;
                        if (i > 0) up = prev[j]; // Paths from above
                        if (j > 0) left = curr[j - 1]; // Paths from the left
                        curr[j] = up + left; // Total paths to current cell
                    }
                }
            }
            prev = curr; // Move current row to previous for next iteration
        }
        
        return prev[n - 1]; // Return paths to the bottom-right corner
    }
};


int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    int ans = sol.uniquePathsWithObstacles(m, n, mat);
    cout << ans;

    return 0;
}
