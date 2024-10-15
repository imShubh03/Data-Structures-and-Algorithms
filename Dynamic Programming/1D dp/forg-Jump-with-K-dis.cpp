#include <bits/stdc++.h>
using namespace std;

/*RECURSIVE time:O(k^n)  space:O(n)
int solve(vector<int> &heights, int ind, int k) {
    if (ind == 0) return 0;
    int minEnergy = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int energy = solve(heights, ind - j, k) + abs(heights[ind] - heights[ind - j]);
            minEnergy = min(minEnergy, energy);
        }
    }
    return minEnergy;
}
int frogJumps(vector<int> &heights, int n, int k) {
    return solve(heights, n - 1, k);
}
*/

/* MEMOISATION space:O(n * k) time:O(n)
int solve(vector<int> &heights, int ind, int k, vector<int> &dp) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int minEnergy = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int energy = solve(heights, ind - j, k, dp) + abs(heights[ind] - heights[ind - j]);
            minEnergy = min(minEnergy, energy);
        }
    }
    dp[ind] = minEnergy;

    return dp[ind];
}
int frogJumps(vector<int> &heights, int n, int k) {
    vector<int> dp(n, -1);
    return solve(heights, n - 1, k, dp);
}
*/

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int ans = frogJumps(heights, n, k);
    cout << ans << endl;

    return 0;
}
