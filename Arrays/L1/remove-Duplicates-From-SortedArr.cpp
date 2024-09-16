#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n){
    set<int>st;
    for(int i =0; i<n; i++){
        st.insert(arr[i]);
    }
    int ind = 0;
    for(auto it: st){
        arr[ind]= it;
        ind++;
    }

    return ind;
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int res = removeDuplicates(arr, n);
    cout<<res<<endl;

    return 0;
}