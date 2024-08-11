#include <bits/stdc++.h>
using namespace std;

// TC : O(n 2^n) (loop*no of recurcall)  SC:O(n)
class Solution{
    public:
    void printSubSets(int index, vector<int>&ans, int arr[], int n){
        //base case 
        if(index ==n){
            for(auto it:ans){
                cout<<it<<" ";
            }
            if(ans.empty()){
                cout<<"[]";
            }
            cout<<endl;
            return;
        }

        //pick the index
        ans.push_back(arr[index]);
        printSubSets(index+1,ans,arr,n);
        ans.pop_back();

        //not pick the elem
        printSubSets(index+1,ans,arr,n);
    }

};

int main() {
    int arr[] ={3,1,2};
    int n = 3;

    vector<int>ans;

    Solution sol;
    sol.printSubSets(0,ans,arr,n);

    return 0;
}