#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    int solve(vector<int> &prices, int n, int ind, int buy){
        // Base case: If we have processed all days
        if(ind == n) return 0;
        int profit = 0;
        if(buy){
            // Two choices: Buy the stock or skip
            profit = max(-prices[ind] + solve(prices, n, ind + 1, 0), solve(prices, n, ind + 1, 1));
        } else {
            // Two choices: Sell the stock or skip
            profit = max(prices[ind] + solve(prices, n, ind + 1, 1), solve(prices, n, ind + 1, 0));
        }
        return profit;
    }

    int maxProfit(vector<int> &prices, int n){
        return solve(prices, n, 0, 1); // Start from day 0 with buying allowed
    }
};
*/

/*
class Solution{
    public:
    int solve(vector<int> &prices, int n, int ind, int buy, vector<vector<int>> &dp){
        // Base case: If we have processed all days
        if(ind == n) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        if(buy){
            // Two choices: Buy the stock or skip
            profit = max(-prices[ind] + solve(prices, n, ind + 1, 0, dp), solve(prices, n, ind + 1, 1, dp));
        } else {
            // Two choices: Sell the stock or skip
            profit = max(prices[ind] + solve(prices, n, ind + 1, 1, dp), solve(prices, n, ind + 1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int> &prices, int n){
        vector<vector<int>>dp(n, vector<int>(2, -1));
        // Start from day 0 with buying allowed
        return solve(prices, n, 0, 1, dp); 
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int> &prices, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case is implicitly handled as the DP table is initialized with 0

        // Fill the DP table in reverse order (bottom-up)
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1]; // Max profit starting from day 0 with the option to buy
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int> &prices, int n) {
        vector<int> ahead(2, 0), curr(2, 0);
        // Base case is implicitly handled as both vectors are initialized to 0
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    curr[buy] = max(-prices[ind] + ahead[0], ahead[1]);
                } else {
                    curr[buy] = max(prices[ind] + ahead[1], ahead[0]);
                }
            }
            ahead = curr; // Move the current state to the next state
        }
        return ahead[1]; // Max profit starting from day 0 with the option to buy
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> prices(n);
    for(int &it: prices){
        cin >> it;
    }

    Solution sol;
    int ans = sol.maxProfit(prices, n);
    cout << ans;

    return 0;
}
