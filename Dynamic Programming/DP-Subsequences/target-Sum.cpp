#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int solve(vector<int> &nums, int ind, int k) {
        // Base cases
        if (ind == 0) {
            if (k == 0 && nums[0] == 0) return 2; // Both +0 and -0 are valid
            if (k == 0 || k == nums[0]) return 1; // Either use nums[0] or not
            return 0; // Invalid case
        }
        int nottake = solve(nums, ind - 1, k);
        int take = 0;
        if (k >= nums[ind]) {
            take = solve(nums, ind - 1, k - nums[ind]);
        }
        return take + nottake;
    }
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        // Check for invalid cases
        if ((totalsum - target) < 0 || (totalsum - target) % 2 == 1) return 0;
        int k = (totalsum - target) / 2;
        return solve(nums, n - 1, k);
    }
};
*/

/* memoisation
class Solution {
public:
    int solve(vector<int> &nums, int ind, int k, vector<vector<int>> &dp) {
        // Base cases
        if (ind == 0) {
            if (k == 0 && nums[0] == 0) return 2; // Both +0 and -0 are valid
            if (k == 0 || k == nums[0]) return 1; // Either use nums[0] or not
            return 0; // Invalid case
        }
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        int nottake = solve(nums, ind - 1, k, dp);
        int take = 0;
        if (k >= nums[ind]) {
            take = solve(nums, ind - 1, k - nums[ind], dp);
        }
        return dp[ind][k] = take + nottake;
    }
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        // Check for invalid cases
        if ((totalsum - target) < 0 || (totalsum - target) % 2 == 1) return 0;
        int k = (totalsum - target) / 2;
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        return solve(nums, n - 1, k, dp);
    }
};
*/

/*
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        // Check for invalid cases
        if ((totalsum - target) < 0 || (totalsum - target) % 2 == 1) return 0;
        int k = (totalsum - target) / 2;

        // Create DP table with n rows and k+1 columns
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // Base case for the first element
        if (nums[0] == 0) {
            dp[0][0] = 2;  // Handle the case where nums[0] = 0 (both +0 and -0 are possible)
        } else {
            dp[0][0] = 1;  // If nums[0] is not 0, there's only one way to form 0
        }

        // If nums[0] is less than or equal to k, initialize the dp[0][nums[0]] cell
        if (nums[0] != 0 && nums[0] <= k) {
            dp[0][nums[0]] = 1;
        }

        // DP transition to fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= k; sum++) {
                // Ways without taking the current element
                int nottake = dp[ind - 1][sum];
                // Ways with taking the current element (if the sum allows)
                int take = 0;
                if (sum >= nums[ind]) {
                    take = dp[ind - 1][sum - nums[ind]];
                }
                dp[ind][sum] = take + nottake;
            }
        }

        // The result is stored in dp[n-1][k], where k is the target sum
        return dp[n - 1][k];
    }
};
*/

//space optimsation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        // Check for invalid cases
        if ((totalsum - target) < 0 || (totalsum - target) % 2 == 1) return 0;

        int k = (totalsum - target) / 2;

        // Use two 1D arrays: `prev` for the previous state and `curr` for the current state
        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        // Base cases
        prev[0] = 1; // Always 1 way to make sum 0
        if (nums[0] == 0) {
            prev[0] = 2; // Special case for nums[0] == 0
        }
        if (nums[0] != 0 && nums[0] <= k) {
            prev[nums[0]] = 1; // If nums[0] is less than or equal to k
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= k; sum++) {
                int nottake = prev[sum];
                int take = 0;
                if (sum >= nums[ind]) {
                    take = prev[sum - nums[ind]];
                }
                curr[sum] = take + nottake;
            }
            prev = curr; // Update `prev` with the values of `curr`
        }

        return prev[k];
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int ans = sol.findTargetSumWays(nums, target);
    cout << ans;

    return 0;
}
