#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    vector<int> rotateArray(vector<int>& arr, int n){
        vector<int>temp = arr;

        for(int i=1; i<n; i++){
            temp[i-1] = arr[i];
        }
        temp[n-1] = arr[0];
        return temp;
    }
};
*/

class Solution{
    public:
    vector<int> rotateArray(vector<int>& arr, int n){
        int temp =arr[0];

        for(int i=0;i<n-1; i++){
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;

        return arr;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int &it : arr){
        cin>>it;
    }

    Solution sol;
    vector<int>ans = sol.rotateArray(arr, n);
    for(int it: ans){
        cout<<it<<" ";
    }

    return 0;
}