#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int lcsHelper(string &str1, string &str2, int m, int n, int &maxLen, vector<vector<int>> &dp) {
        if (m == 0 || n == 0) {
            return 0;
        }

        // If already computed
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        // If characters match
        if (str1[m - 1] == str2[n - 1]) {
            dp[m][n] = 1 + lcsHelper(str1, str2, m - 1, n - 1, maxLen, dp);
            maxLen = max(maxLen, dp[m][n]);
        } else {
            dp[m][n] = 0; // Reset for non-matching substring
        }

        // Return the length of the current longest common substring
        return dp[m][n];
    }

    int lcs(string &str1, string &str2) {
        int m = str1.length();
        int n = str2.length();
        int maxLen = 0;

        // Initialize memoization table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // Calculate LCS for all suffixes
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                lcsHelper(str1, str2, i, j, maxLen, dp);
            }
        }

        return maxLen;
    }
};
*/


class Solution {
public:
    int lcs(string &str1, string &str2) {
        int m = str1.length();
        int n = str2.length();
        int ans = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
*/

int main() {
    string str1, str2;

    // Input the two strings
    cin >> str1 >> str2;

    // Create an instance of the Solution class
    Solution sol;

    // Call the lcs function and print the result
    cout << sol.lcs(str1, str2) << endl;

    return 0;
}
