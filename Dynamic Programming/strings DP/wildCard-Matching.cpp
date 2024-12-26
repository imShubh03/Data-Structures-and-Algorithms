#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    // Recursive function to check for wildcard matching
    bool solve(string &s, int i, string &t, int j) {
        // Base case: both strings are completely processed
        if (i < 0 && j < 0) return true;

        // Base case: pattern exhausted but text remains
        if (i < 0 && j >= 0) return false;

        // Base case: text exhausted but pattern remains
        if (i >= 0 && j < 0) {
            // Remaining characters in the pattern must all be '*'
            for (int ii = 0; ii <= i; ii++) {
                if (s[ii] != '*') {
                    return false;
                }
            }
            return true;
        }

        // Case: characters match or pattern has '?'
        if (s[i] == t[j] || s[i] == '?') {
            return solve(s, i - 1, t, j - 1);
        }

        // Case: pattern has '*', which can match zero or more characters
        if (s[i] == '*') {
            return solve(s, i - 1, t, j) || solve(s, i, t, j - 1);
        }

        // Case: characters do not match
        return false;
    }

    // Function to initiate the matching process
    bool isMatch(string &s, string &t) {
        int m = s.size();
        int n = t.size();
        return solve(s, m - 1, t, n - 1);
    }
};
*/

/*
class Solution {
public:
    // Recursive function with memoization to check for wildcard matching
    bool solve(string &s, int i, string &t, int j, vector<vector<int>> &dp) {
        // Base case: both strings are completely processed
        if (i < 0 && j < 0) return true;

        // Base case: pattern exhausted but text remains
        if (i < 0 && j >= 0) return false;

        // Base case: text exhausted but pattern remains
        if (i >= 0 && j < 0) {
            // Remaining characters in the pattern must all be '*'
            for (int ii = 0; ii <= i; ii++) {
                if (s[ii] != '*') {
                    return false;
                }
            }
            return true;
        }

        // Check if already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Case: characters match or pattern has '?'
        if (s[i] == t[j] || s[i] == '?') {
            return dp[i][j] = solve(s, i - 1, t, j - 1, dp); 
        }

        // Case: pattern has '*', which can match zero or more characters
        if (s[i] == '*') {
            return dp[i][j] = solve(s, i - 1, t, j, dp) || solve(s, i, t, j - 1, dp);
        }

        // Case: characters do not match
        return dp[i][j] = false;
    }

    // Function to initiate the matching process
    bool isMatch(string &s, string &t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, m - 1, t, n - 1, dp);
    }
};
*/


class Solution {
public:
    bool isMatch(string &s, string &t) {
        int m = s.size();
        int n = t.size();

        // Create a DP table
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base cases
        dp[0][0] = true; // Both strings are empty
        for (int i = 1; i <= m; i++) {
            // Pattern can match an empty string if all characters up to i are '*'
            if (s[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1] || s[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (s[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};


int main() {
    string s, t;
    cin >> s; 
    cin >> t; 

    Solution sol;
    bool ans = sol.isMatch(s, t); // Check if the pattern matches the text

    // Output the result
    if (ans) {
        cout << "matches";
    } else {
        cout << "doesnt match";
    }

    return 0;
}
