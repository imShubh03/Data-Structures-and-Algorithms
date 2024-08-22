#include <bits/stdc++.h>
using namespace std;

/* time:O(n^2)   space:O(1)
int longestSubarrayWithSumLessOrEqual(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen=0;

    for(int i =0; i<n; i++){
        int sum =0;
        for(int j =i; j<n; j++){
            sum = sum + arr[j];

            if(sum<=k){
                maxLen = max(maxLen, j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxLen;
}
*/

// time :O(n) space:O(1)
class Solution {
public:
    int longestSubarrayWithSumLessOrEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;
        int currentSum = 0;
        int l = 0; 
        int r = 0;
        
        while (r < n) {
            // Add the current element to the sum
            currentSum += nums[r];

            // Shrink the window from the left until the sum is less than or equal to k
            while (currentSum > k && l <= r) {
                currentSum -= nums[l];
                l++;
            }

            // Update the maximum length of a valid subarray
            maxLength = max(maxLength, r - l + 1);

            // Move the right pointer forward
            r++;
        }

        return maxLength;
    }
};



int main() {
    vector<int> arr1 = {1, 2, 1, 0, 1, -8, -9, 0};
    int k1 = 4;
    cout << "Longest Subarray Length with sum <= " << k1 << " is : " << longestSubarrayWithSumLessOrEqual(arr1, k1) << endl;
    
    return 0;
}
