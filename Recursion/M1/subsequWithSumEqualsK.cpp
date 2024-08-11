#include <bits/stdc++.h>
using namespace std;

/*  which prints all subsequences
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
*/

/*
//code which prints only one of the subsequence
class Solution{
    public:
    bool subseqWithSumK(int index, vector<int>&ans, int sum, int k, int arr[], int n){
        //base case
        if(index==n){
            if(sum ==k){
                for(auto it: ans){
                    cout<<it<<" ";
                }
                cout<<endl;
                return true;
            }
            else{
                return false;
            }
        }

        //take the index
        ans.push_back(arr[index]);
        sum+=arr[index];

        if(subseqWithSumK(index+1,ans,sum, k,arr,n)==true){
            return true;
        }

        sum-=arr[index];
        ans.pop_back();

        //not pick
        if(subseqWithSumK(index+1,ans,sum,k,arr,n)==true){
            return true;
        }

        return false;
    }
};
*/

//prints the number of subsequences
class Solution{
public:
    int subseqWithSumK(int index, int sum, int k, int arr[], int n) {
        // base case
        if (index == n) {
            if (sum == k) {
                return 1;
            }
            return 0;
        }

        sum+=arr[index];
        // Include the current element
        int l = subseqWithSumK(index + 1, sum + arr[index], k, arr, n);

        sum-=arr[index];

        // Exclude the current element
        int r = subseqWithSumK(index + 1, sum, k, arr, n);

        // Return the count of valid subsequences from both options
        return l + r;
    }
};



int main() {
    int n = 3;
    int arr[] = {1, 2, 1};
    int k = 2;
    vector<int> ans;

    Solution sol;
    // sol.subseqWithSumK(0, ans, 0, k, arr, n);


    //for number of subsequences
    cout<<"number of subsequences are "<<sol.subseqWithSumK(0, 0, k, arr, n);

    return 0;
}