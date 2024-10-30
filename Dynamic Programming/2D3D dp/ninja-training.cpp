#include <bits/stdc++.h>
using namespace std;

/* Recursive solution
class Solution {
private:
    int solve(vector<vector<int>> &pts, int day, int lastTask) {
        // Base case
        if (day == 0) {
            int maxpts = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != lastTask) {
                    maxpts = max(maxpts, pts[0][task]);
                }
            }
            return maxpts;
        }

        // For the rest of the days
        int maxpts = 0;
        for (int task = 0; task <= 2; task++) {
            if (task != lastTask) {
                int currpts = pts[day][task] + solve(pts, day - 1, task); // Find current points and call for the previous day with updated task
                maxpts = max(maxpts, currpts);
            }
        }
        return maxpts;
    }
public:
    int maximumpts(vector<vector<int>> &pts, int n) {
        return solve(pts, n - 1, 3); // Start with the last day n-1 and lastTask = 3, i.e., no task initially
    }
};
*/


/* memoization
class Solution {
private:
    int solve(vector<vector<int>> &pts, int day, int lastTask, vector<vector<int>> &dp) {
        // Base case
        if (day == 0) {
            int maxpts = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != lastTask) {
                    maxpts = max(maxpts, pts[0][task]);
                }
            }
            return maxpts;
        }

        // Check if the result is already computed
        if (dp[day][lastTask] != -1) {
            return dp[day][lastTask];
        }

        // For the rest of the days
        int maxpts = 0;
        for (int task = 0; task <= 2; task++) {
            if (task != lastTask) {
                int currpts = pts[day][task] + solve(pts, day - 1, task, dp); // Find current points and call for the previous day with updated task
                maxpts = max(maxpts, currpts);
            }
        }

        // Memoize the result
        return dp[day][lastTask] = maxpts;
    }
public:
    int maximumpts(vector<vector<int>> &pts, int n) {
        // Initialize memoization table with -1
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(pts, n - 1, 3, dp); // Start with the last day n-1 and lastTask = 3, i.e., no task initially
    }
};
*/

/* tabulation
class Solution{
    public:
    int maximumpts(vector<vector<int>> &pts, int n){
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day = 0
        dp[0][0] = max(pts[0][1], pts[0][2]);
        dp[0][1] = max(pts[0][0], pts[0][2]);
        dp[0][2] = max(pts[0][0], pts[0][1]);
        dp[0][3] = max({pts[0][0], pts[0][1], pts[0][2]});

        // Fill the dp table
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;

                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        int currpts = pts[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], currpts);
                    }
                }
            }
        }

        // Return the maximum points on the last day with no task restriction
        return dp[n-1][3];
    }
};
*/


class Solution {
    public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Initialize a 1D array for storing previous day's results
        vector<int> prev(4, 0);

        // Base case for day = 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        // Iterate over days to fill the dp table
        for(int day = 1; day < n; day++) {
            vector<int> curr(4, 0);

            for(int last = 0; last < 4; last++) {
                curr[last] = 0;

                for(int task = 0; task <= 2; task++) {
                    if(task != last) {
                        int currPoints = arr[day][task] + prev[task];
                        curr[last] = max(curr[last], currPoints);
                    }
                }
            }

            // Update prev to curr for the next iteration
            prev = curr;
        }

        // Return the maximum points achievable on the last day without any task restriction
        return prev[3];
    }
};



int main() {
    int n;
    cin >> n;

    vector<vector<int>> pts(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2; j++) {
            cin >> pts[i][j];
        }
    }

    Solution sol;
    int ans = sol.maximumpts(pts, n);
    cout << ans;

    return 0;
}
