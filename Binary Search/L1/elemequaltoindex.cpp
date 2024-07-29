// given an sorted  array of n distinct elements find any elemt a[i] = i
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int indexequalsValue(vector<int>&arr){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int count = 0;
        while (low <= high)
        {
            int mid = (low + high)/2;
            count++;
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
        cout<< count <<endl;
        return -1;
        // -150 -100 -90 -80 -70 -50 -20 -10 -5 -3 0 3 7 9 10 13 17 20 25 30 35 50 55 60 70 90 200 210 220 
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