#include <bits/stdc++.h>
using namespace std;

/* recursion time:O(2^(m * n)) space:O(len of path)
class Solution{
    private:
    int solve(int i, int j){
        //base case
        if(i == 0 && j == 0) return 1;
        //out of bond case
        if(i < 0 || j< 0) return 0;

        //move left
        int left = solve(i - 1, j);
        //move right
        int right = solve(i, j -1);

        ///sum up path from both dire
        return left + right;
    }
    public:
    int uniquePaths(int m, int n){
        return solve(m-1, n-1);
    }
};
*/

/*memoisation time:O(m * n) space:O(m+n) + O(m * n)
class Solution {
    private:
    int solve(int i, int j, vector<vector<int>> &dp){
        // base case
        if(i ==0 && j == 0){
            return 1;
        }
        if(i <0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = solve(i -1, j, dp);
        int right = solve(i, j-1, dp);

        dp[i][j] = left + right;

        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};
*/

/* tabulation  time:O(m * n) space:O(m * n)
class Solution{
    public:
    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0) left = dp[i-1][j];
                    if(j > 0) up = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};
*/

//space optimsation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n, 0);
        for(int i =0; i<m; i++){
            vector<int>curr(n, 0);
            for(int j =0; j<n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                }
                else{
                    int up =0, left =0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main() {
    int m, n;
    cin>>m>>n;

    Solution sol;
    int ans = sol.uniquePaths(m, n); //start from bottom right
    cout<<ans;

    return 0;
}