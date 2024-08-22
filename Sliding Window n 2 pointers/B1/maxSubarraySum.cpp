#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& arr, int k) {
    int n= arr.size();
    int l =0;
    int r=0;
    int sum =0;
    int maxSum=INT_MIN;

    if(n<k) return -1;

    for(int r =0; r<n; r++){
        sum += arr[r];

        if(r>=k-1){
            maxSum = max(maxSum, sum);
            sum -= arr[l];
            l++;
        }
    }
    return maxSum;

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    cout << "Maximum Subarray Sum of size " << k << ": " << maxSubArraySum(arr, k) << endl;
    return 0;
}
