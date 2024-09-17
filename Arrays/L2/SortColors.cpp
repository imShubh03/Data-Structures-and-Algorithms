#include <bits/stdc++.h>
using namespace std;


/*  time : O(nlogn) space:O(1)
class Solution{
    public:
    void sortColors(vector<int>&nums){
        sort(nums.begin(),nums.end());
    }
};
*/

/*
//better time:O(2*n)  space:O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        // Count the number of 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else if (nums[i] == 1) {
                ones++;
            } else {
                twos++;
            }
        }
        
        int i = 0;
        while (zeros > 0) {
            nums[i] = 0;
            i++;
            zeros--;
        }
        while (ones > 0) {
            nums[i] = 1;
            i++;
            ones--;
        }
        while (twos > 0) {
            nums[i] = 2;
            i++;
            twos--;
        }
    }
};
*/

// optimal: DNF(Dutch National Flag) Algorithm  time:O(n) space:O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // DNF algorithm
        int n = nums.size();
        int low =0, mid =0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
