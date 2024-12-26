#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    int solve(string &s, int i, string &t, int j){
        //base cases
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(s[i] == t[j]) return 0 + solve(s, i-1, t, j-1);

        return 1 + min(solve(s, i-1, t, j), min(solve(s, i, t, j-1), solve(s, i-1, t, j-1)));
    }
    int minDistance(string &word1, string &word2){
        int m = word1.size();
        int n = word2.size();

        return solve(word1, m-1, word2, n-1);
    }
};
*/

/*
class Solution{
    public:
    int solve(string &s, int i, string &t, int j, vector<vector<int>> &dp){
        //base cases
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 0 + solve(s, i-1, t, j-1, dp);

        return dp[i][j] = 1 + min(solve(s, i-1, t, j, dp), min(solve(s, i, t, j-1, dp), solve(s, i-1, t, j-1, dp)));
    }
    int minDistance(string &word1, string &word2){
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(word1, m-1, word2, n-1, dp);
    }
};
*/

/*
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();

        // Create a DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; 
        for (int j = 0; j <= n; j++) dp[0][j] = j; 

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No cost if characters match
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j],                // Delete
                                       min(dp[i][j - 1],          // Insert
                                           dp[i - 1][j - 1]));    // Replace
                }
            }
        }

        // Return the result in dp[m][n]
        return dp[m][n];
    }
};
*/

class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();

        // Create a DP table
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Fill the base cases
        for (int j = 0; j <= n; j++) prev[j] = j; 

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            curr[0] = i; // Base case for the current row
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1]; 
                } else {
                    curr[j] = 1 + min(prev[j],                // Delete
                                       min(curr[j - 1],          // Insert
                                           prev[j - 1]));        // Replace
                }
            }
            prev = curr; // Move current row to previous row
        }

        // Return the result in prev[n]
        return prev[n];
    }
};

int main() {
    string s, t;
    cin>>s;
    cin>>t;

    Solution sol;

    int ans = sol.minDistance(s, t);
    cout<<ans<<endl;


    return 0;
}