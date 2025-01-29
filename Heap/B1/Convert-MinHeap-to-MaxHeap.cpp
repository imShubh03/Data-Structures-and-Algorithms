#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;    
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i = N/2 - 1; i>=0; i--){
            heapify(arr, N, i);
        }
    }
    
};

int main() {
    
    int n;
    vector<int>arr(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    sol.convertMinToMaxHeap(arr, n);

    for(int i =0; i<n; i++){
        cout<< arr[i] << " ";
    }


    return 0;
}