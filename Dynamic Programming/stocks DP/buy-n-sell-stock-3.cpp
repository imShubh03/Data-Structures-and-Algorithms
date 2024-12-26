#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int>& prices, int ind, int buy, int cap) {
        // base case
        int n = prices.size();
        if (ind == n)
            return 0;
        if (cap == 0)
            return 0;
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + solve(prices, ind + 1, 0, cap),
                            solve(prices, ind + 1, 1, cap));
        } else {
            profit = max(prices[ind] + solve(prices, ind + 1, 1, cap - 1),
                            solve(prices, ind + 1, 0, cap));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, 0, 1, 2);
    }
};
*/

/*
class Solution {
public:
    int solve(vector<int>& prices, int ind, int buy, int cap,
                            vector<vector<vector<int>>>& dp) {
        // base case
        int n = prices.size();
        if (ind == n)
            return 0;
        if (cap == 0)
            return 0;
        int profit = 0;

        if (dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }

        if (buy) {
            profit = max(-prices[ind] + solve(prices, ind + 1, 0, cap, dp),
                            solve(prices, ind + 1, 1, cap, dp));
        } else {
            profit = max(prices[ind] + solve(prices, ind + 1, 1, cap - 1, dp),
                            solve(prices, ind + 1, 0, cap, dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(prices, 0, 1, 2, dp);
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // base cases
        for (int ind = 0; ind <= n; ind++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[ind][buy][0] = 0;
            }
        }

        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[0][buy][cap] = 0;
            }
        }
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        dp[ind][buy][cap] =
                            max(-prices[ind] + dp[ind + 1][0][cap],
                                dp[ind + 1][1][cap]);
                    } else {
                        dp[ind][buy][cap]  = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
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
        return after[1][2];
    }
};

int main() {
    int n;
    cin>>n;

    vector<int>prices(n);

    for(int &it: prices){
        cin>>it;
    }

    Solution sol;
    int ans = sol.maxProfit(prices);
    cout<<ans;

    return 0;
}