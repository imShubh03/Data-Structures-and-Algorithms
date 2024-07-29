#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // REMEMBER: the no of times array is rotated = index of min elem in array :)
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int index = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }

            // Eliminate left half if it is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {6, 7, 9, 15, 19, 2, 3};
    int index = solution.findKRotation(arr);
    cout << "The array is rotated " << index << " times.\n";
    return 0;
}
