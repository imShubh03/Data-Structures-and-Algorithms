#include <bits/stdc++.h>
using namespace std;

/*brute force time:O(n^2) space:O(1)
class Solution{
    // generate all subarray
    public:
    int lenOfLongestSubarr(vector<int>&arr, int k){
        int n = arr.size();
        int len = 0;
        for(int i =0; i<n; i++){
            int sum = 0;
            for(int j =i; j<n; j++){
                sum += arr[j];

                if(sum == k){
                    len = max(len, j-i+1);
                }
            }
        }
        return len;
    }
};
*/

/* BETTER prefix sum time:O(n logn) space:O(n)
class Solution{
    public:
    int lenOfLongestSubarr(vector<int>&arr, int k) {
        int n = arr.size();
        map<int, int>mp;
        int sum = 0;
        int maxLen = 0;

        for(int i =0; i<n; i++){
            sum += arr[i];
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }

            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxLen = max(maxLen, len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
*/

// optimal 2 pointers only for 0 & +ve arr values time:O(2n) space:O(1)
class Solution{
    public:
    int lenOfLongestSubarr(vector<int>&arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int sum = arr[0];
        int maxLen = 0;
        while(r < n){
            while(l <= r && sum > k){
                sum -= arr[l];
                l++;
            }
            if(sum == k){
                maxLen = max(maxLen, r - l + 1);

            }
            r++;
            if(r<n) sum += arr[r];
        }
        return maxLen;
    }
};

int main() {
    int n, k;
    cin>>n;

    vector<int>arr(n);

    for(int &it : arr){
        cin>>it;
    }

    cin>>k;

    Solution sol;
    int ans = sol.lenOfLongestSubarr(arr, k);
    cout<<ans;
    

    return 0;
}