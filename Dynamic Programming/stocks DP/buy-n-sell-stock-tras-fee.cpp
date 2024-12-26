#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int>& prices, int fee, int ind, int buy, vector<vector<int>>& dp) {
        // Base case: when index exceeds the array bounds
        if (ind == prices.size()) return 0;

        // Memoization check
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        // Recursive cases: Buy or Sell based on current state
        if (buy) {
            profit = max(-prices[ind] + solve(prices, fee, ind + 1, 0, dp), 
                         solve(prices, fee, ind + 1, 1, dp));
        } else {
            profit = max(prices[ind] - fee + solve(prices, fee, ind + 1, 1, dp), 
                         solve(prices, fee, ind + 1, 0, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, fee, 0, 1, dp); // Start with buying state
    }
};
*/


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // Create a dp table for storing the results
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case initialization: already 0
        // dp[n][0] = dp[n][1] = 0;

        // Fill the table in reverse (from the last day to the first)
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], 
                                        dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] - fee + dp[ind + 1][1], 
                                        dp[ind + 1][0]);
                }
            }
        }

        // The answer will be at dp[0][1], starting with buy = 1
        return dp[0][1];
    }
};

int main() {
    Solution obj;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << "Maximum Profit: " << obj.maxProfit(prices, fee) << endl;

    return 0;
}
