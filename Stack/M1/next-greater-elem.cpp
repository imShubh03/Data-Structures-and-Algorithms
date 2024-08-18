#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* brute force :time:O(n^2) space:O(n)
    vector<int> nextGreaterElement(vector<int>& arr, int n) {
        vector<int> ans(n, -1);  // Initialize value -1

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
    */
    vector<int> nextGreaterElement(vector<int>& arr, int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]= st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    vector<int> result = solution.nextGreaterElement(arr, n);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
