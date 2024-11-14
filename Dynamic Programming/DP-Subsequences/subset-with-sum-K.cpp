#include <bits/stdc++.h>
using namespace std;

/*recursion time:O(2^n) space:O(n)
class Solution{
    public:
    int solve(vector<int> &arr, int ind, int k){
        //base cases
        if(k == 0) return 1;
        if(ind == 0){
            return (arr[ind]==k);
        }
        int notpick = solve(arr, ind-1, k);
        int pick = 0;
        if(k >= arr[ind]){
            pick = solve(arr, ind-1, k - arr[ind]);
        }
        return pick + notpick;
    }
    int findWays(vector<int> &arr, int k){
        int n= arr.size();

        return solve(arr, n-1, k);
    }
};
*/

/*  memoisation time:O(n * k) space:O(n * K) + O(n)
class Solution{
    public:
    int solve(vector<int> &arr, int ind, int k, vector<vector<int>> &dp){
        //base cases
        if(k == 0) return 1;
        if(ind == 0){
            return (arr[ind]==k) ? 1 : 0;
        }
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        
        int notpick = solve(arr, ind-1, k, dp);
        int pick = 0;
        if(k >= arr[ind]){
            pick = solve(arr, ind-1, k - arr[ind], dp);
        }
        return dp[ind][k] = pick + notpick;
    }
    int findWays(vector<int> &arr, int k){
        int n= arr.size();
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        return solve(arr, n-1, k, dp);
    }
};
*/

/* tabulation
class Solution {
public:
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        // Base cases
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        if (k >= arr[0]) dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= k; sum++) {
                int nottake = dp[ind - 1][sum];
                int take = 0;
                if (sum >= arr[ind]) {
                    take = dp[ind - 1][sum - arr[ind]];
                }
                dp[ind][sum] = nottake + take;
            }
        }
        return dp[n - 1][k];
    }
};
*/

//space optimsation
class Solution {
public:
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prev(k + 1, 0), curr(k + 1, 0);
        // Base cases
        prev[0] = 1;
        if (k >= arr[0]) prev[arr[0]] = 1;
        for (int ind = 1; ind < n; ind++) {
            curr[0] = 1;  // Initialize the current row's sum = 0 case
            for (int sum = 1; sum <= k; sum++) {
                int nottake = prev[sum];
                int take = (sum >= arr[ind]) ? prev[sum - arr[ind]] : 0;
                curr[sum] = nottake + take;
            }
            prev = curr;  
        }
        return prev[k];
    }
};

int main() {
    int n, k;
    cin>>n;

    vector<int>arr(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    cin>>k;

    Solution sol;
    int ans = sol.findWays(arr, k);
    cout<<ans<<endl;

    return 0;
}