#include <bits/stdc++.h>

using namespace std;

/* brute force: time:O(n^3)  space: O(1)
class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int n = nums.size();
        int maxi= INT_MIN;

        //2 loops to find every possible subarray
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                int sum = 0;
                //now find max sum in subarray [i.....j]
                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }
                maxi= max(maxi,sum);
            }
        }
        return maxi;
    }
};
*/

/* better  : time O(n^2) space: O(1)
class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int n = nums.size();
        int maxi= INT_MIN;

        for(int i =0;i<n;i++){
            int sum =0;
            for(int j =i;j<n;j++){
                //we have sub arr [i.....j]
                // add j to sum  ie arr[j] and find the maxi
                sum+=nums[j];
                maxi = max(sum,maxi);
            }
        }
        return maxi;
    }
};
*/

//optimal: KADANES ALGO  : time:O(n) space:O(1)
class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int sum =0;
        int maxi = INT_MIN;

        for(auto it:nums){
            sum+=it;
            maxi = max(maxi,sum);

            if(sum<0) sum =0;
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int>nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = sol.maxSubArray(nums);
    cout<<"the max subarray is of size "<<ans<<endl;


    return 0;
}