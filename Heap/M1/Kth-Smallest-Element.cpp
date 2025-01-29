#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
    public:
    int kthSmallest(vector<int>&arr, int n, int k){
        sort(arr.begin(), arr,end());

        return arr[k-1];
    }
};
*/

class Solution{
    public:
    int kthSmallest(vector<int>&arr, int n, int k){
        priority_queue<int>pq;

        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }

        for(int i = k; i<n; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};

int main() {
    
    int n, k;
    cin>>n >> k;

    vector<int>arr(n);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    int ans = sol.kthSmallest(arr, n, k);
    cout<< ans <<endl;

    return 0;
}