#include <bits/stdc++.h>
using namespace std;

/* brute: time:O(nlogn)+O(n)   space:O(n)
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
*/
// optimal: 2 pointers time:O(n) space:O(1)
int removeDuplicates(int arr[], int n){
    int i =0;
    // first ele already in correct pos so j from 1
    for(int j =1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1]= arr[j];
            i++;
        }
    }
    return i+1;
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