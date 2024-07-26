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



//optimised time:O(n)  space:O(n)
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
