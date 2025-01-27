#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
public:
    int subarraysWithKDistinct(vector<int>nums, int k){
        int n = nums.size();
        int cnt = 0;

        for(int i =0; i<n; i++){
            map<int, int>mp;
            for(int j = i; j<n; j++){
                mp[nums[j]]++;

                if(mp.size() > k){
                    break;
                }
                else if(mp.size() < k){
                    continue;
                }
                else if(mp.size() == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
*/


class Solution{
public:
    int solve(vector<int>nums, int k){
        int n = nums.size();
        int left = 0, right = 0;
        int cnt = 0;
        map<int, int>mp;
        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                l++;
            }

            cnt += (right - left + 1);

            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>nums, int k){
        return solve(nums, k) - solve(nums, k-1);
    }
};


int main() {

    int n, k;
    cin>>n>>k;

    vector<int>nums(n);

    for(int &it : nums){
        cin>> it;
    }
    Solution sol;
    int ans = sol.subarraysWithKDistinct(nums, k);
    cout<< ans << endl;


    return 0;
}