#include<bits/stdc++.h>
using namespace std;

/* brute : time:O(n)  space:O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
        return -1;
    }
};
*/

//optimised : time:O(logn) space:O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return n-1;

        int low =1;
        int high = n-2;
        while(low<=high){
            int mid = (low + high)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid] >nums[mid-1]){
                //we r on increasi curve so peak wi be on right
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1}; // Example input

    int result = solution.findPeakElement(nums);
    cout << "The peak element is at index: " << result << endl;

    return 0;
}
