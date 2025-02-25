#include<bits/stdc++.h>
using namespace std;

/*
int unique(int arr[], int n){
    sort(arr, arr+n);
    for(int i=1; i<n; i+=2){
        if(arr[i] != arr[i-1]){
            return arr[i-1];
        }
    }
    return nums[i-1];
}
*/

/*
int unique(int arr[], int n){
    unordered_map<int, int>mp;
    for(int it : arr){
        mp[it]++;
    }
    for(auto it : mp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}
*/

int unique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        //we know XOR properties
        // a^a=0 and 0^a=a
        ans=ans^arr[i];
    }
    return ans;
}


int main(){
    int arr[6]={1,5,8,5,1};
    int ans = unique(arr,5);
    cout<<ans;
    return 0;
}