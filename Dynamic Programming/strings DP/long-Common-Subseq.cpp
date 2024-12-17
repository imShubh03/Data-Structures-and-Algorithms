#include <bits/stdc++.h>
using namespace std;

/* recursion time:O(2^m 2^n) space:O(min(m, n));
class Solution {
public:
    int solve(string &s1, int i, string &s2, int j) {
        // Base case
        if (i < 0 || j < 0) {
            return 0;
        }

        // Characters match
        if (s1[i] == s2[j]) {
            return 1 + solve(s1, i - 1, s2, j - 1);
        }

        // Characters don't match, take the maximum of two cases
        return max(solve(s1, i - 1, s2, j), solve(s1, i, s2, j - 1));
    }

    int longestCommonSubsequence(string &s1, string &s2) {
        return solve(s1, s1.size() - 1, s2, s2.size() - 1);
    }
};
*/

//memoisation time:O(m * n) space(O(m * n) + O(m+n))
/*
class Solution {
public:
    int solve(string &s1, int i, string &s2, int j, vector<vector<int>> &dp) {
        // Base case
        if (i < 0 || j < 0) {
            return 0;
        }

        // Check if already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s1, i - 1, s2, j - 1, dp);
        }

        // Characters don't match, take the maximum of two cases
        return dp[i][j] = max(solve(s1, i - 1, s2, j, dp), solve(s1, i, s2, j - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(text1, m - 1, text2, n - 1, dp);
    }
};
*/

/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;  // Copy current row to previous row for the next iteration
        }

        return prev[n];
    }
};

int main() {
    string text1, text2;

    getline(cin, text1);
    getline(cin, text2);

    Solution sol;
    int ans = sol.longestCommonSubsequence(text1, text2);
    cout << ans;

    return 0;
}
