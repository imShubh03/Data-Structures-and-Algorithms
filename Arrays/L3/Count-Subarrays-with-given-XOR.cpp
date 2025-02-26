#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
    public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        int cnt = 0;
        
        for(int i =0; i<n; i++){
            for(int j = i; j <n; j++){
                long xorSum = 0;
                
                for(int k = i; k<=j; k++){
                    xorSum = xorSum ^ arr[k];
                }
                
                if(xorSum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
*/

/*
class Solution {
    public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        int cnt = 0;
        
        for(int i =0; i<n; i++){
            long xorSum = 0;
            for(int j = i; j <n; j++){
                xorSum = xorSum ^ arr[j];

                if(xorSum == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
*/

class Solution {
    public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int xr = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; // Initialize with {0, 1} before traversal

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i];

            // Check if (xr ^ k) exists in map
            if (mp.count(xr ^ k)) {
                cnt += mp[xr ^ k];
            }

            // Update frequency of current xor
            mp[xr]++;
        }
        return cnt;
    }
};

int main() {
    
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int &i : arr){
        cin>> i;
    }

    Solution sol;
    int ans = sol.subarrayXor(arr);
    cout<< ans<<endl;

    return 0;
}