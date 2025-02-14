#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b) {
        return a[2] > b[2]; // Sort by profit in descending order
    }

    vector<int> jobScheduling(vector<vector<int>> &jobs) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), comparator); // Sort jobs based on profit

        int maxProfit = 0, cnt = 0;
        int maxDeadline = -1;

        // Find the maximum deadline
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i][1]);
        }

        vector<int> hash(maxDeadline + 1, -1); // Job slot tracking

        // Traverse through all jobs
        for (int i = 0; i < n; i++) {
            int deadline = jobs[i][1];
            int profit = jobs[i][2];

            // Find the latest available slot before or on the deadline
            for (int j = deadline; j > 0; j--) {
                if (hash[j] == -1) { // If slot is empty
                    hash[j] = jobs[i][0];
                    maxProfit += profit;
                    cnt++;
                    break;
                }
            }
        }

        return {cnt, maxProfit};
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> jobs(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
    }

    Solution sol;
    vector<int> res = sol.jobScheduling(jobs);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}
