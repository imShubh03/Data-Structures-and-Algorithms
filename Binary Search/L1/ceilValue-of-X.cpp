#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    int ceilSearch(vector<int> &arr, int n, int x){
        for(int i =0; i<n; i++){
            if(arr[i] >= x){
                return arr[i];
            }
        }
        return -1;
    }
};
*/

class Solution{
    public:
    int ceilSearch(vector<int> &arr, int n, int x){
        int l = 0;
        int h = n-1;
        int ans = -1;

        while(l <= h){
            int m = (l+h)/2;
            if(arr[m] >= x){
                ans = arr[m];
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }
};

int main() {
    int n, x;
    cin>>n>>x;

    vector<int>arr(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;

    int ans = sol.ceilSearch(arr, n, x);
    cout<<ans;

    return 0;
}