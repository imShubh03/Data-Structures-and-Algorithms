#include <bits/stdc++.h>
using namespace std;

/* recursive  time:O(2^n)  space:O(n)
int solve(vector<int>& heights, int ind) {
    if (ind == 0) return 0;

    int left = solve(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1) {
        right = solve(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
    }

    return min(left, right);
}
int frogjumps(vector<int>& heights, int n) {
    return solve(heights, n - 1 );
}
*/

/*memoisation time:O(n) space:O(n) + O(n)
int solve(vector<int> &heights, int ind, vector<int>&dp){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int left = solve(heights, ind-1, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;

    if(ind > 1){
        right = solve(heights, ind -2, dp) + abs(heights[ind] - heights[ind - 2]);
    }
    dp[ind] = min(left, right);

    return dp[ind];
}
int frogjumps(vector<int>& heights, int n) {
    vector<int>dp(n+1, -1);
    return solve(heights, n - 1, dp);
}
*/

/*TABULATION time:O(n) space:O(n)
int frogjumps(vector<int> &heights, int n){
    vector<int>dp(n, 0);
    dp[0] = 0;
    for(int i =1; i<n; i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1){
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}
*/

//space optimisation time:O(n) space:O(1)
int frogjumps(vector<int> &heights, int n){
    int prev1 =0;
    int prev2 =0;

    for(int i =1; i<n; i++){
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss= prev2 + abs(heights[i] - heights[i-2]);
        }

        int curr = min(fs, ss);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int ans = frogjumps(heights, n);
    cout << ans << endl;

    return 0;
}
