#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i =0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j] && abs(i-j) <= k){
                    return true;
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //map -> val, index
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            if(mp.count(nums[i]) == 1){
                if(i - mp[nums[i]] <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
int main() {

    int n, k;
    cin>>n>>k;

    vector<int>nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    Solution sol;
    bool ans = sol.containsNearbyDuplicate(nums, k);

    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }


    return 0;
}