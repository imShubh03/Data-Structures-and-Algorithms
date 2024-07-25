#include <bits/stdc++.h>

using namespace std;

/* time:O(n)  space:O(n)
class Solution{
    public:
    int singleNumber(vector<int>&nums){
        int n = nums.size();
        unordered_map<int,int>map;
        for(int i =0;i<n;i++){
            map[nums[i]]++;
        }

        int ans =0;
        for(auto it: map){
            if(it.second==1){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};
*/


//optimal  time:O(n) space:O(1)
class Solution{
    public:
    int singleNumber(vector<int>&nums){
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    Solution sol;
    int ans = sol.singleNumber(nums);
    
    cout<<"answer is "<<ans<<endl;

    return 0;
}