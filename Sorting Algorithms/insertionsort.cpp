#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&arr, int n){
    for(int i=0;i<=n-1;i++){
        int j =i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j]= temp;
            j--;
        }
    }
}


int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}