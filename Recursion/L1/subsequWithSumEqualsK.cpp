#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void subseqWithSumK(int index, vector<int>&ans, int sum, int k, int arr[], int n){
        //base case
        if(index==n){
            if(sum ==k){
                for(auto it: ans){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
            return;
        }

        //take the index
        ans.push_back(arr[index]);
        sum+=arr[index];
        subseqWithSumK(index+1,ans,sum, k,arr,n);
        sum-=arr[index];
        ans.pop_back();

        //not take index
        subseqWithSumK(index+1,ans,sum,k,arr,n);
    }
};

int main() {
     int n = 3;
    int arr[] = {1, 2, 1};
    int k = 2;
    vector<int> ans;

    Solution sol;
    sol.subseqWithSumK(0, ans, 0, k, arr, n);
    return 0;
}