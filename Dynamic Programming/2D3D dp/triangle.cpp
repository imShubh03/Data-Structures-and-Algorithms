#include <bits/stdc++.h>
using namespace std;

/* recursive :
class Solution {
public:
    int minimumTotal(int i, int j, vector<vector<int>> &triangle) {
        int m = triangle.size();
        if (i == m - 1) return triangle[i][j];
        
        int down = triangle[i][j] + minimumTotal(i + 1, j, triangle);
        int diag = triangle[i][j] + minimumTotal(i + 1, j + 1, triangle);
        
        return min(down, diag);
    }
};
*/

/*
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int m = triangle.size();
        if (i == m - 1) return triangle[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(0, 0, triangle, dp);
    }
};
*/

/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        // Base case: initialize the last row of dp with values from triangle
        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }
        // Fill dp table from bottom to top
        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0]; // The minimum path sum from the top
    }
};
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> front(m, 0);

        // Initialize `front` with the last row of the triangle as the base case
        for (int j = 0; j < m; j++) {
            front[j] = triangle[m - 1][j];
        }

        // Fill from bottom to top using two arrays: `curr` for the current row and `front` for the next row
        for (int i = m - 2; i >= 0; i--) {
            vector<int> curr(m, 0); // Temporary array for the current row
            for (int j = 0; j <= i; j++) {
                int down = front[j];              // Value directly below
                int diag = front[j + 1];          // Value diagonally below to the right
                curr[j] = triangle[i][j] + min(down, diag);
            }
            front = curr; // Move current row results to front
        }

        return front[0]; // The minimum path sum from the top
    }
};


int main() {
    int m;
    cin >> m;

    vector<vector<int>> triangle(m);
    for(int i = 0; i < m; i++) {
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    Solution sol;
    int ans = sol.minimumTotal(triangle);
    cout << ans;

    return 0;
}
