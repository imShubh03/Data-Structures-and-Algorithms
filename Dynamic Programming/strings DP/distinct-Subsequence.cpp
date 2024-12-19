#include <bits/stdc++.h>
using namespace std;

/* time:O(2^(m+n)) space:O(m+n)
class Solution{
    public:
    int solve(string &s, int i, string &t, int j){
        //base case
        if(j<0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]){
            return solve(s, i-1, t, j-1) + solve(s, i-1, t, j);
        }
        // else
        return solve(s, i-1, t, j);
    }
    int numDistinct(string &s, string &t){
        int m = s.length();
        int n = t.length();

        return solve(s, m-1, t, n-1);
    }
};
*/

/*memoisation time:O(m*n) space:O(m*n) + O(m+n)
class Solution{
    public:
    int solve(string &s, int i, string &t, int j, vector<vector<int>> &dp){
        //base case
        if(j<0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];

        }
        if(s[i] == t[j]){
            return dp[i][j] = solve(s, i-1, t, j-1, dp) + solve(s, i-1, t, j, dp); 
        }
        // else
        return dp[i][j] = solve(s, i-1, t, j, dp);
    }
    int numDistinct(string &s, string &t){
        int m = s.length();
        int n = t.length();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(s, m-1, t, n-1, dp);
    }
};
*/

/* tabulation time:O(m*n) space:O(m*n)
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Create dp table with dimensions (m+1) x (n+1)
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1; // Empty `t` can always be formed from any prefix of `s`
        }

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Result is in dp[m][n]
        return (int)dp[m][n];
    }
};
*/

// space optimsation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Initialize previous and current row vectors
        vector<double> prev(n + 1, 0), curr(n + 1, 0);

        // Base case: Empty `t` can always be formed
        prev[0] = curr[0] = 1;

        // Fill the DP rows
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            // Update previous row with current row
            prev = curr;
        }

        // Result is in the last cell of the prev vector
        return (int)prev[n];
    }
};

int main() {
    string s, t;
    cin>>s>>t;

    Solution sol;
    int ans = sol.numDistinct(s, t);
    cout<<ans;

    return 0;
}