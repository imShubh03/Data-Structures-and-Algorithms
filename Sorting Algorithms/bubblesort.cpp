#include<bits/stdc++.h>
using namespace std;

/*
void bubble_sort(vector<int>&arr, int n){
    for(int i=n-1;i>=0;i++){
        for(int j =0;j<i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
            }
        }
    }
}

*/

/*
optimisd bubble sort
best case O(n)
*/

void bubble_sort(vector<int>&arr, int n){
    for(int i=n-1;i>=0;i++){
        int didSwap =0;
        for(int j =0;j<i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
                didSwap=1;
            }
        }
        if(didSwap == 0){
            break;
        }
        // verify
        cout<<"Runs"<<endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
