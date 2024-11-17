#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
    public:
    int solve(vector<int>& coins, int ind, int amount) {
        if (amount == 0) return 0;
        if (ind == 0) {
            if (amount % coins[ind] == 0) {
                return amount / coins[ind];
            } else {
                return 1e9;
            }
        }

        int nottake = solve(coins, ind - 1, amount);
        int take = INT_MAX;
        if (amount >= coins[ind]) {
            take = 1 + solve(coins, ind, amount - coins[ind]);
        }

        return min(nottake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int result = solve(coins, n - 1, amount);
        return result >= 1e9 ? -1 : result;
    }
};
*/

/* memoisation
class Solution {
    public:
    int solve(vector<int>& coins, int ind, int amount, vector<vector<int>> &dp) {
        if (amount == 0) return 0;
        if (ind == 0) {
            if (amount % coins[ind] == 0) {
                return amount / coins[ind];
            } else {
                return 1e9;
            }
        }
        if(dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        int nottake = solve(coins, ind - 1, amount, dp);
        int take = INT_MAX;
        if (amount >= coins[ind]) {
            take = 1 + solve(coins, ind, amount - coins[ind], dp);
        }

        return dp[ind][amount] = min(nottake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int result = solve(coins, n - 1, amount, dp);
        return result >= 1e9 ? -1 : result;
    }
};
*/

/* tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create a 2D DP table with n rows and amount+1 columns
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0]; // Minimum coins needed for amount i using coins[0]
            }
        }
        
        // Fill the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                // Calculate the minimum elements needed without taking the current coin
                int notTake = dp[ind - 1][target];
                
                // Calculate the minimum elements needed by taking the current coin
                int take = INT_MAX; // Initialize 'take' to a very large value
                if (coins[ind] <= target) {
                    take = 1 + dp[ind][target - coins[ind]]; // Corrected dp index
                }
                
                // Store the minimum of 'notTake' and 'take' in the DP table
                dp[ind][target] = min(notTake, take);
            }
        }
        
        // The answer is in the bottom-right cell of the DP table
        int ans = dp[n - 1][amount];
        
        // If 'ans' is still INT_MAX, it means it's not possible to form the target amount
        return (ans == INT_MAX) ? -1 : ans;
    }
};
*/


//space optimsation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create a 1D DP table for storing the results of previous and current rows
        vector<int> prev(amount + 1, INT_MAX);
        vector<int> curr(amount + 1, INT_MAX);
        
        // Initialize the base case for the first coin
        prev[0] = 0; // 0 coins are needed to make amount 0
        
        // Fill the DP table using a bottom-up approach
        for (int ind = 0; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                // If we don't take the current coin, the value remains the same as previous row
                int notTake = prev[target];
                
                // If we take the current coin, check if it's valid and update the value
                int take = INT_MAX;
                if (coins[ind] <= target) {
                    take = 1 + curr[target - coins[ind]];
                }
                
                // Store the minimum of 'notTake' and 'take' in the current row
                curr[target] = min(notTake, take);
            }
            
            // After processing the current coin, update the prev array to be the same as curr
            prev = curr;
        }
        
        // The answer is in the last cell of the current row (prev at the last iteration)
        int ans = prev[amount];
        
        // If 'ans' is still INT_MAX, it means it's not possible to form the target amount
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    int n, amount;
    cin>>n>>amount;

    vector<int>coins(n);

    for(int i =0; i<n; i++){
        cin>>coins[i];
    }

    Solution sol;
    int ans = sol.coinChange(coins, amount);
    cout<<ans;

    return 0;
}