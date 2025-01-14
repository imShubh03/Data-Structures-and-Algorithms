#include <bits/stdc++.h>
using namespace std;

/* time:O(maxim in arr)*O(n) ~ O(n^2)  space:O(1)
class Solution {
public:
    int sumbyD(vector<int>& nums, int d) {
        int n = nums.size();
        int sum = 0;

        for(int i =0; i<n; i++) {
            sum += (nums[i] + d - 1)/d;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        for(int d = 1; d<=maxi; d++) {
            if(sumbyD(nums, d) <= threshold) {
                return d;
            }
        }
        return -1;
    }
};
*/

// time: O(log(max in arr))* O(n) ~ O(n logn)    space:O(1)
class Solution {
public:
    int sumbyD(vector<int>& nums, int d) {
        int sum = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            sum += (nums[i] + d - 1) / d; 
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(sumbyD(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;  // Try to find a smaller divisor
            } else {
                low = mid + 1;  // Try to find a larger divisor
            }
        }
        return ans;
    }
};



int main() {
    Solution sol;
    int n, threshold;
    
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> threshold;

    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}
