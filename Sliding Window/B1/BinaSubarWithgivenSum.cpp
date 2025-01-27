#include <bits/stdc++.h>
using namespace std;

/* brute: time :O(n^2) space:O(1)
class Solution{
    public:
    int numSubarraysWithSum(vector<int>&nums, int goal){
        int n = nums.size();
        int cnt=0;
        for(int i =0; i<n; i++){
            int sum =0;
            for(int j =i; j<n; j++){
                sum += nums[j];

                // to avoid tle, first 
                if(sum > goal){
                    break;
                }

                if(sum == goal){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
*/

// optimised time:O(4n) space:O(1)
class Solution {
public:
    int findAns(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, cnt = 0;
        while (r < n) {
            sum = sum + nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //inoder to find no of subarray w sum == goal ==> we do like subarr w sum (goal) - subarr w sum(goal - 1);
        int ans = findAns(nums, goal) - findAns(nums, goal - 1);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int>arr = {1,0,1,0,1};
    int goal = 2;
    int ans = sol.numSubarraysWithSum(arr, goal);
    cout<<"ans is "<<ans<<endl;
    return 0;
}