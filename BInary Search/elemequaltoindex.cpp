// given an sorted  array of n distinct elements find any elemt a[i] = i
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int indexequalsValue(vector<int>&arr){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while (low <= high)
        {
            int mid = (low + high)/2;

            if(arr[mid] == mid){
                return mid;
            }
            else if(mid > arr[mid]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
        
    }
};
int main() {
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    vector<int>arr(n);

    cout<<"enter element in arr"<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    Solution sol;
    int ans = sol.indexequalsValue(arr);

    cout<<"ans is "<< ans <<endl;


    return 0;
}