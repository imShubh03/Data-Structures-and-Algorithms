#include <bits/stdc++.h>
using namespace std;

/*  brute force , time:O(n) spaceO(1)
class Solution{
    public:
    int lowerBound(vector<int> arr, int n, int x) {

        for(int i =0;i<n;i++){
            if(arr[i] == x) return i;
        }
        return -1;
    }
};
*/


/*
//  better: time: O(logn) space:O(1)
class Solution{
public:
    int lowerBound(vector<int> arr, int n, int x){
        int low = 0;
        int high = n - 1;
        // if no ans poss then return n
        int ans = n;
        while (low <= high){
            int mid = (low + high) / 2;
            if (arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
*/

//optimal: using c++ STL 
class Solution{
    public:
    int lowerBound(vector<int> arr, int n, int x){
        int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        return lb;
    }
};



int main(){
    vector<int> arr = {3, 5, 8, 8, 15, 19, 29};
    int x = 16;
    Solution sol;
    int index = sol.lowerBound(arr, arr.size(), x);
    cout << "Lower bound of " << x << " is at index: " << index << endl;

    return 0;
}
