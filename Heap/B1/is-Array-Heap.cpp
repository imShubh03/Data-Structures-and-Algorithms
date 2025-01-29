#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isMaxHeap(int arr[], int n){
        for(int i =0; i<n; i++){
            int left = 2*i+1;
            int right = 2*i+2;
            if(arr[left] > arr[i] || arr[right] > arr[i]){
                return false;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    if(sol.isMaxHeap(arr, n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}