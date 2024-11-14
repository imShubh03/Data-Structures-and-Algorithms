#include <bits/stdc++.h>
using namespace std;

//TC:O(N* totalsum) space:O(n*totalsum)
int minSubsetSumDifference(vector<int>& nums, int n) {
    int totalsum = accumulate(nums.begin(), nums.end(), 0);
    int k = totalsum;
    vector<vector<int>> dp(n, vector<int>(k + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (k >= nums[0]) dp[0][nums[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (target >= nums[ind]) take = dp[ind - 1][target - nums[ind]];
            dp[ind][target] = take || nottake;
        }
    }

    int mini = INT_MAX;
    for (int s1 = 0; s1 <= totalsum / 2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalsum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minSubsetSumDifference(nums, n);
    cout << "The minimum subset sum difference is: " << result << endl;

    return 0;
}
