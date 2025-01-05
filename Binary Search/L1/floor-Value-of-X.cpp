#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    int floorSearch(vector<int> & arr, int x, int n) {
        
        for(int i =n -1; i>= 0; i--){
            if(arr[i] <= x){
                return arr[i];
            }
        }
        return -1;
    }
};
*/

class Solution{
    public:
    int floorSearch(vector<int> & arr, int x, int n) {
        
        int l = 0;
        int h = n-1;
        int ans = -1;

        while(l <= h){
            int m = (l + h)/2;
            if(arr[m] <= x){
                ans = arr[mid];
                l = m+1;
            }
            else{
                h = m -1;
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

    int ans = sol.floorSearch(arr, n, x);
    cout<<ans;

    return 0;
}