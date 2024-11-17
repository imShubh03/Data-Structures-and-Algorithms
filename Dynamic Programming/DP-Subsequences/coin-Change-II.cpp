#include <bits/stdc++.h>
using namespace std;

/* recursion
class Solution {
public:
    int solve(vector<int>& coins, int ind, int k) {
        // Base case
        if (ind == 0) {
            if (k % coins[0] == 0) return 1;
            else return 0;
        }
        int nottake = solve(coins, ind - 1, k);
        int take = 0;
        if (k >= coins[ind]) {
            take = solve(coins, ind, k - coins[ind]);
        }
        return take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(coins, n - 1, amount);
    }
};
*/

/* memoisation
class Solution {
public:
    int solve(vector<int>& coins, int ind, int k, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (k % coins[0] == 0) return 1;
            else return 0;
        }
        if (dp[ind][k] != -1) return dp[ind][k];
        int nottake = solve(coins, ind - 1, k, dp);
        int take = 0;
        if (k >= coins[ind]) {
            take = solve(coins, ind, k - coins[ind], dp);
        }
        dp[ind][k] = take + nottake;
        return dp[ind][k];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
    }
};
*/

/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base cases
        for (int k = 0; k <= amount; k++) {
            if (k % coins[0] == 0) dp[0][k] = 1;
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int k = 0; k <= amount; k++) {
                int nottake = dp[ind - 1][k];
                int take = 0;
                if (k >= coins[ind]) {
                    take = dp[ind][k - coins[ind]];
                }
                dp[ind][k] = take + nottake;
            }
        }

        return dp[n - 1][amount];
    }
};
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case
        for (int k = 0; k <= amount; k++) {
            if (k % coins[0] == 0) prev[k] = 1;
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int k = 0; k <= amount; k++) {
                int nottake = prev[k];
                int take = 0;
                if (k >= coins[ind]) {
                    take = curr[k - coins[ind]];
                }
                curr[k] = take + nottake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};


int main() {
    int n, amount;
    cin >> n >> amount;  

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];  
    }

    Solution sol;
    cout << sol.change(amount, coins) << endl;  

    return 0;
}
