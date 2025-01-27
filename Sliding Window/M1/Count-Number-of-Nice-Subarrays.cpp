#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
public:
    int numberOfSubarrays(vector<int>&nums, int k){
        int n = nums.size();
        int ans = 0;
        for(int i =0; i<n; i++){
            int cnt = 0;
            for(int j = i; j<n; j++){
                if(nums[j] % 2 != 0){
                    cnt++;
                }

                if(cnt == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};
*/

class Solution{
public:
    int numberOfSubarrays(vector<int>&nums, int k){
        int n = nums.size();

    }
};

int main() {
    int n, k;
    cin>>n >> k;

    vector<int>nums(n);

    for(int i =0; i<n; i++){
        cin>> nums[i];
    }

    cin>>k;

    Solution sol;
    int ans = sol.numberOfSubarrays(nums, k);
    cout<<ans;

    return 0;
}