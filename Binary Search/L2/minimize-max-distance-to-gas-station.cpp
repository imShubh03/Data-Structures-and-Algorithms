#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();

        // Vector to track how many gas stations are added between consecutive points
        vector<int> howMany(n - 1, 0);

        // Add gas stations one by one
        for (int gasSt = 1; gasSt <= k; gasSt++) {
            long double maxSec = -1; // Track the current maximum segment length
            int maxIdx = -1;        // Track the index of the maximum segment

            // Iterate over all segments to find the segment with the maximum length
            for (int j = 0; j < n - 1; j++) {
                long double diff = (arr[j + 1] - arr[j]); // Calculate the segment length
                long double secLenj = diff / (long double)(howMany[j] + 1); // Calculate new segment length if split

                // Update the maximum segment length and its index
                if (secLenj > maxSec) {
                    maxSec = secLenj;
                    maxIdx = j;
                }
            }
            // Add a gas station to the segment with the maximum length
            howMany[maxIdx]++;
        }

        long double maxAns = -1; // Track the maximum segment length after adding gas stations

        // Calculate the maximum segment length after all gas stations are added
        for (int i = 0; i < n - 1; i++) {
            long double diff = (arr[i + 1] - arr[i]); // Calculate the segment length
            long double secLenj = diff / (long double)(howMany[i] + 1); // Calculate the length of subsegments
            maxAns = max(maxAns, secLenj); // Update the maximum segment length
        }

        // Return the minimized maximum segment length
        return maxAns;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;

    double ans = sol.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << ans << endl; // Output with 6 decimal precision

    return 0;
}
