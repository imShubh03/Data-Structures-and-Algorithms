#include <bits/stdc++.h>
using namespace std;

/*
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
*/

class Solution {
public:

    // REMEMBER: the no of times array is rotated = index of min elem in array :)
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int idx = -1;

        while (l <= h) {
            if (nums[l] <= nums[h]) {
                idx = l; // Smallest element is at index 'l'
                break;
            }

            int m = (l + h) / 2;

            if (nums[l] <= nums[m]) {
                l = m + 1; // The left half is sorted, move to the right half
            } else {
                h = m; // The pivot is in the left half, update 'h'
            }
        }

        return idx;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {6, 7, 9, 15, 19, 2, 3};
    int index = solution.findKRotation(arr);
    cout << "The array is rotated " << index << " times.\n";
    return 0;
}
