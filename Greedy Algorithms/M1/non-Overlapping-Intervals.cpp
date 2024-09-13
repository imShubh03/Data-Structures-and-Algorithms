#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Comparator for sorting by end time
    static bool comparator(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; // Handle empty input

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), comparator);

        int cnt = 1; // Count of non-overlapping intervals
        int lastEnd = intervals[0][1]; // End time of the first interval

        // Iterate through sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEnd) { // Check for non-overlapping
                cnt++;
                lastEnd = intervals[i][1]; // Update end time
            }
        }

        // Return number of intervals to remove
        return intervals.size() - cnt;
    }
};

int main() {
    Solution obj;
    
    // Test case: list of intervals
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    
    // Call the function and print the result
    int result = obj.eraseOverlapIntervals(intervals);
    cout << "Number of intervals to remove: " << result << endl;
    
    return 0;
}
