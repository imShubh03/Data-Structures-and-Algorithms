#include <bits/stdc++.h>
using namespace std;

/*recursive : time:O(2^n) spcace:O(n)
int solve(vector<int>&nums, int ind){
    // base case
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    // pick the elem but not adj
    int pick = nums[ind] + solve(nums, ind - 2);
    // not pick
    int notpick = 0 + solve(nums, ind - 1);
    return max(pick, notpick);
}
int rob(vector<int>&nums, int n){
    return solve(nums, n-1);
}
*/

/* MEMOISATION time:O(n) space:O(n) + O(n)
int solve(vector<int>&nums, int ind, vector<int> &dp){
    // base case
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1){
        return dp[ind];
    }
    // pick the elem but not adj
    int pick = nums[ind] + solve(nums, ind - 2, dp);
    // not pick
    int notpick = 0 + solve(nums, ind - 1, dp);
    dp[ind] = max(pick, notpick);
    return dp[ind];
}
int rob(vector<int>&nums, int n){
    vector<int>dp(n+1, -1);
    return solve(nums, n-1, dp);
}
*/

/*tabulation  time:O(n) space:O(n)
int rob(vector<int>& nums, int n) {
    vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) pick += dp[i - 2];
        int notpick = dp[i - 1];

        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}
*/

// space optimisation time:O(n) space:O(1)
int rob(vector<int>& nums, int n) {
    
    int prev2 = 0, prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) pick += prev2;
        int notpick = prev1;

        int curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main() {
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i =0; i<n; i++){
        cin>>nums[i];
    }

    int ans = rob(nums, n);
    cout<<ans<<endl;

    return 0;
}