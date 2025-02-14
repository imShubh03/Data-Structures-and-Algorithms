#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start, end, pos; // Meeting details: start time, end time, and position
};

class Solution {
public:
    // Static comparator to sort meetings by end time coz itwill give me faster meetings greedily and then position
    static bool comparator(meeting m1, meeting m2) {
        if (m1.end < m2.end) return true; // Earlier end time comes first
        if (m1.end > m2.end) return false; // Later end time comes later
        return m1.pos < m2.pos; // If end times are the same, sort by position
    }

    int maxMeetings(int start[], int end[], int n) {
        meeting arr[n]; // Array to hold meeting details
        for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1; // Position of meeting (1-based index)
        }

        sort(arr, arr + n, Solution::comparator); // Sort meetings using comparator

        int cnt = 1; // Count of meetings
        int freetime = arr[0].end; // End time of the first meeting
        vector<int> posAns; // To store positions of selected meetings
        posAns.push_back(arr[0].pos); // Add the first meeting's position

        for (int i = 1; i < n; i++) {
            if (arr[i].start > freetime) { // If meeting starts after the last one ended
                cnt++; // Increment meeting count
                freetime = arr[i].end; // Update free time to current meeting's end
                posAns.push_back(arr[i].pos); // Add meeting's position to result
            }
        }

        return cnt; // Return maximum number of meetings
    }
};

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};

    Solution obj;
    int result = obj.maxMeetings(start, end, n);
    cout << "Maximum number of meetings: " << result << endl; // Output result

    return 0;
}
