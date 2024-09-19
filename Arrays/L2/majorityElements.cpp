#include <bits/stdc++.h>
using namespace std;

/*  brute : time:O(n^2)  space:O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int i =0;i<n;i++){
            int cnt =0;
            for(int j =0;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt > (n/2)){
                return nums[i];  // Return the majority element
                break; 
            }
        }  
        return -1; 
    }
};
*/


/*better:  time:O(nlogn) space:O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int req= n/2;
        map<int,int>mpp;
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second > req){
                return it.first;
            }
        }
        return -1;
    }
};
*/

// optimal : moores voting algo time:O(n) space:O(1)
class Solution{
    public:
    int majorityElement(vector<int>& nums){
        int n = nums.size();
        int cnt =0;
        int ele;
        for(int i =0; i<n; i++){
            if(cnt ==0){
                ele = nums[i];
                cnt =1;
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        // we have our elem here
        int ans = 0;
        for(int i =0; i<n; i++){
            if(nums[i] == ele){
                ans++;
            }
        }
        if(ans > (n/2)){
            return ele;
        }
        return -1;
    }
};


int main() {
    // Test case
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority element is : " << result << endl;

    return 0;
}
