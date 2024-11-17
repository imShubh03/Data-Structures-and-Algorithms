#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int solve(vector<int> &arr, int ind, int k, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (k == 0 && arr[0] == 0) return 2;
            if (k == 0 || k == arr[0]) return 1;
            return 0;
        }
        if (dp[ind][k] != -1) {
            return dp[ind][k];
        }

        int notpick = solve(arr, ind - 1, k, dp) % MOD;
        int pick = 0;
        if (k >= arr[ind]) {
            pick = solve(arr, ind - 1, k - arr[ind], dp) % MOD;
        }
        return dp[ind][k] = (pick + notpick) % MOD;
    }

    int findWays(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(arr, n - 1, k, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        if (totalsum - d < 0 || (totalsum - d) % 2 == 1) return 0;
        int target = (totalsum - d) / 2;
        return findWays(arr, target);
    }
};

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.countPartitions(n, d, arr) << endl;
    return 0;
}
