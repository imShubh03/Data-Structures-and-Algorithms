#include <bits/stdc++.h>
using namespace std;

/* recurson : time:O(2 ^n) space:O(n)
class Solution{
    public:
    bool solve(vector<int> &arr, int ind, int target){
        //base case
        if(target == 0) return true;

        if(ind == 0) return (arr[ind] == target);

        //bool take
        bool nottake = solve(arr, ind - 1, target);

        bool take = false;
        if(target >= arr[ind]){
            take = solve(arr, ind -1 , target - arr[ind]);
        }

        return nottake || take ;
    }
    bool isSubsetSum(vector<int> &arr, int n, int target){
        return solve(arr, n-1, target);
    }
};
*/

/* memoisation time:O(n*target)  space:O(n*target) + O(n)
class Solution{
    public:
    bool solve(vector<int> &arr, int ind, int target, vector<vector<int>> &dp){
        //base case
        if(target == 0) return true;

        if(ind == 0) return (arr[ind] == target);

        if(dp[ind][target] != -1) {
            return dp[ind][target];
        }

        //bool take
        bool nottake = solve(arr, ind - 1, target, dp);

        bool take = false;
        if(target >= arr[ind]){
            take = solve(arr, ind -1 , target - arr[ind], dp);
        }



        return dp[ind][target] =  nottake || take ;
    }
    bool isSubsetSum(vector<int> &arr, int n, int target){
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return solve(arr, n-1, target, dp);
    }
};
*/

/* tabulation
class Solution{
    public:
    bool isSubsetSum(vector<int> &arr, int n, int target) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: If target is 0, it can always be achieved with an empty subset
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: If only one element is considered
        if (arr[0] <= target) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int targ = 1; targ <= target; targ++) {
                bool nottake = dp[ind - 1][targ];

                bool take = false;
                if (targ >= arr[ind]) {
                    take = dp[ind - 1][targ - arr[ind]];
                }

                dp[ind][targ] = nottake || take;
            }
        }

        return dp[n - 1][target];
    }
};
*/

//space optimisation
class Solution { 
public:
    bool isSubsetSum(vector<int> &arr, int n, int target) { 
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = curr[0] = true;

        // Base case: If only one element is considered
        if (arr[0] <= target) {
            prev[arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int targ = 1; targ <= target; targ++) {
                bool nottake = prev[targ];
                bool take = false;

                if (targ >= arr[ind]) {
                    take = prev[targ - arr[ind]];
                }

                curr[targ] = nottake || take;
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main()
{
    int n, target;

    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    Solution sol;

    bool res = sol.isSubsetSum(arr, n, target);

    if (res)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}