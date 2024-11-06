#include <bits/stdc++.h>
using namespace std;

/*Recursive solution
class Solution{
    public:
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) return INT_MAX;

        // Base case: if we reach the first row
        if (i == 0) return matrix[i][j];

        // Recursive calls for the three possible paths
        int up = solve(i - 1, j, matrix);
        int ld = solve(i - 1, j - 1, matrix);
        int rd = solve(i - 1, j + 1, matrix);

        return matrix[i][j] + min({up, ld, rd});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minpath = INT_MAX;

        // Call solve for each element in the last row
        for (int j = 0; j < n; j++) {
            minpath = min(minpath, solve(n - 1, j, matrix));
        }
        return minpath;
    }
};
*/

/* memoisation
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) return INT_MAX;

        // Base case: if we reach the first row
        if (i == 0) return matrix[i][j];

        // Check if the result is already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls for the three possible paths
        int up = solve(i - 1, j, matrix, dp);
        int ld = solve(i - 1, j - 1, matrix, dp);
        int rd = solve(i - 1, j + 1, matrix, dp);

        // Store and return the result
        return dp[i][j] = matrix[i][j] + min({up, ld, rd});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minpath = INT_MAX;

        // Initialize dp table with -1 for memoization
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Call solve for each element in the last row and compute minimum path sum
        for (int j = 0; j < n; j++) {
            minpath = min(minpath, solve(n - 1, j, matrix, dp));
        }

        return minpath;
    }
};
*/

/* tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Initialize dp table
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Copy the last row of matrix as the base case in dp
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Fill dp table from the second-to-last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int up = dp[i + 1][j];
                int ld = INT_MAX;
                int rd = INT_MAX;

                // Update ld if within bounds
                if (j > 0) {
                    ld = dp[i + 1][j - 1];
                }

                // Update rd if within bounds
                if (j < n - 1) {
                    rd = dp[i + 1][j + 1];
                }

                dp[i][j] = matrix[i][j] + min(up, min(ld, rd));
            }
        }

        // Find the minimum value in the top row of dp
        int minpath = dp[0][0];
        for (int j = 1; j < n; j++) {
            if (dp[0][j] < minpath) {
                minpath = dp[0][j];
            }
        }

        return minpath;
    }
};
*/


//space optimis
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Initialize `prev` as the last row of the matrix
        vector<int> prev = matrix[n - 1];

        // Fill the dp arrays from the second-to-last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n);  // Current row in dp
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int ld = INT_MAX;
                int rd = INT_MAX;

                // Check bounds for left diagonal
                if (j > 0) {
                    ld = prev[j - 1];
                }

                // Check bounds for right diagonal
                if (j < n - 1) {
                    rd = prev[j + 1];
                }

                // Compute the current cell value
                curr[j] = matrix[i][j] + min(up, min(ld, rd));
            }
            prev = curr;  // Update prev to be the current row
        }

        // Find the minimum value in `prev`, which represents the top row results
        int minpath = prev[0];
        for (int j = 1; j < n; j++) {
            if (prev[j] < minpath) {
                minpath = prev[j];
            }
        }

        return minpath;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    int result = sol.minFallingPathSum(matrix);
    cout << result << endl;

    return 0;
}
