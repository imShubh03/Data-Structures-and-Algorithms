#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int> &prices, int n, int ind, int buy) {
        // Base case
        if (ind >= n) return 0;

        int profit = 0;

        if (buy == 1) {
            profit = max(-prices[ind] + solve(prices, n, ind + 1, 0),
                            solve(prices, n, ind + 1, 1));
        } else {
            profit = max(prices[ind] + solve(prices, n, ind + 2, 1),
                            solve(prices, n, ind + 1, 0));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, n, 0, 1);
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Create DP table with 2 states (buy or not buy)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Traverse from the last index back to the first index
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                            dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],
                                            dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1]; // Start from index 0 with the intention to buy
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead1(2, 0); // For the next day
        vector<int> ahead2(2, 0); // For the day after the next

        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> curr(2, 0); // Current day's states

            // Buy state
            curr[1] = max(-prices[ind] + ahead1[0], ahead1[1]);

            // Sell state
            curr[0] = max(prices[ind] + ahead2[1], ahead1[0]);

            // Update for the next iteration
            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1]; // Profit starting from day 0 in buy state
    }
};

int main() {
    Solution obj;

    vector<int> prices = {1, 2, 3, 0, 2}; // Example input
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;

    return 0;
}
