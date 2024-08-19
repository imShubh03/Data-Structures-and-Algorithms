#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*  time:O(3n) space:O(2n)
    int trap(vector<int>&arr){
        int n = arr.size();
        //if less than 2 poles then not possible

        if(n<3){
            return 0;
        }

        vector<int>leftmax(n), rightmax(n);
        int total =0;

        // Fill leftMax array
        leftmax[0]= arr[0];
        for(int i =1; i<n;i++){
            leftmax[i] = max(leftmax[i-1], arr[i]);
        }
        
        // Fill rightmax array
        rightmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1], arr[i]);
        }

        //find water trapped

        for(int i =0; i<n; i++){
            total += min(leftmax[i], rightmax[i]) - arr[i];
        }

        return total;
    }
    */

    //OPTIMISED : time:O(n) space:O(1)
    int trap(vector<int>&arr){
        int rightmax=0;
        int leftmax=0;
        int total = 0;
        int l =0;
        int r = arr.size()-1;

        while(l<r){
            if(arr[l] <= arr[r]){
                if(leftmax > arr[l]){
                    total += leftmax - arr[l];
                }
                else{
                    leftmax = arr[l];
                }
                l++;
            }
            else{
                if(rightmax > arr[r]){
                    total += rightmax - arr[r];
                }
                else{
                    rightmax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = sol.trap(arr);

    cout<<"the max water can be stored is "<<res<<endl;

    return 0;
}