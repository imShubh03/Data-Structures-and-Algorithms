#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int>& prices, int ind, int buy, int cap,
                vector<vector<vector<int>>>& dp, int k) {
        if (ind == prices.size() || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;

        if (buy) {
            profit = max(-prices[ind] + solve(prices, ind + 1, 0, cap, dp, k),
                            solve(prices, ind + 1, 1, cap, dp, k));
        } else {
            profit = max(prices[ind] + solve(prices, ind + 1, 1, cap - 1, dp, k),
                            solve(prices, ind + 1, 0, cap, dp, k));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return solve(prices, 0, 1, k, dp, k);
    }
};
*/

/*
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Base cases are already initialized to 0 in the dp table

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                                                dp[ind + 1][1][cap]);
                    } else {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                                dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 1) {
                        curr[buy][cap] =
                            max(-prices[ind] + after[0][cap], after[1][cap]);
                    } else {
                        curr[buy][cap] =
                            max(prices[ind] + after[1][cap - 1], after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};

int main() {
    Solution obj;
    int k = 3; 
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << "Maximum Profit: " << obj.maxProfit(k, prices) << endl;

    return 0;
}
