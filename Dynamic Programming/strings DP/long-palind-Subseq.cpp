#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public: 
    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i == j) return 1; // Single character is a palindrome
        if (i > j) return 0;  // Invalid substring
        
        // Check memoization table
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
        }
        
        // If characters don't match, take the maximum
        return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize memoization table
        return solve(s, 0, n - 1, dp); // Start recursion
    }
};
*/

class Solution {
public: 
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table
        
        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the table for substrings of length 2 and more
        for (int len = 2; len <= n; len++) { // len is the length of substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // End index of substring
                
                if (s[i] == s[j]) { // If characters match
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else { // If characters don't match
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The result is in dp[0][n-1] (whole string)
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
