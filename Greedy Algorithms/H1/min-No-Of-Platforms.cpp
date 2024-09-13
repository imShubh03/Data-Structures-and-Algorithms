#include <bits/stdc++.h>
using namespace std;

/* brute time:O(n^2) space:O(1)
class Solution {
    public:
    // Function to find the minimum number of platforms required
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int max_platforms = 1; // At least 1 platform is needed

        // Loop through each train
        for (int i = 0; i < n; i++) {
            int platform_needed = 1; // Current train needs one platform
            
            // Check how many trains overlap with train `i`
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // Check if train `i` is at the station while train `j` is also present
                    if (arr[i] >= arr[j] && arr[i] <= dep[j]) {
                        platform_needed++; // Train `j` also needs a platform
                    }
                }
            }
            // Update the maximum platforms required
            max_platforms = max(max_platforms, platform_needed);
        }
        
        return max_platforms; // Return the maximum platforms needed at any time
    }
};
*/

//optimised time:O(2* nlogn)+ O(2n)   space:O(1)
class Solution {
    public:
    // Function to find the minimum number of platforms required
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size(); // Size of arrival and departure arrays
        
        // Sort both the arrival and departure arrays
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int maxcnt = 0, cnt = 0;

        // Traverse the sorted arrival and departure arrays
        while (i < n && j < n) {
            // If the next train arrives before the current one departs, increase the platform count
            if (arr[i] <= dep[j]) {
                cnt++; // More platforms needed
                i++;   // Move to the next arrival
            } 
            // Else, decrease the platform count as one train departs
            else {
                cnt--; // Platform freed
                j++;   // Move to the next departure
            }

            // Update the maximum number of platforms needed
            maxcnt = max(maxcnt, cnt);
        }

        return maxcnt;
    }
};

int main() {
    Solution sol;

    // Example case 1
    vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum platforms needed : " 
         << sol.findPlatform(arr1, dep1) << endl; // Output: 3


    return 0;
}
