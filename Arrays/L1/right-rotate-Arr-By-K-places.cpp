#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int s, int e){
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void rotate(int arr[], int n, int k){
    k = k % n;

    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

    // print arr
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}

int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;
    rotate(arr, n, k);

    return 0;
}