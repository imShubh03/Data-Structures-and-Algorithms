#include <bits/stdc++.h>

using namespace std;

/*  brute force time O(n^2)  space: O(1)
class Solution{
    public:
    vector<int>twoSum(vector<int>&nums, int target){
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
*/


/* better : time:O(NlogN)  space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i =0;i<n;i++){
            int num = nums[i];
            int moreNeeded= target - nums[i];
            if(mpp.find(moreNeeded)!=mpp.end()){
                return {mpp[moreNeeded],i};
            }
            mpp[num]=i;
        }
        return {};
    }
};
*/

//optimal: sort and then two pointers time: O(nlogn)  space:O(1)
//returns true or false.....not the indexes
class Solution {
public:
    bool twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left =0;
        int right=n-1;
        while(left<right){
            int sum = nums[left]+ nums[right];
            if(sum == target){
                return true;
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
        
    }
};



int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    /*  for returning the indexes
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    */

    bool ans = sol.twoSum(nums, target);
    cout<<"ans is "<<ans<<endl;
    

    return 0;
}