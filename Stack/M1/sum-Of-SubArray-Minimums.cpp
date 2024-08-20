#include <bits/stdc++.h>
using namespace std;

/*  time: O(n^2) space:O(1)
class Solution{
public:
    
    int minimumSum(vector<int> &arr, int n) {
        long long ans = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int mini = arr[i];
            for (int j = i; j < n; j++) {
                mini = min(mini, arr[j]);
                ans = (ans + mini) % mod;
            }
        }
        return ans;
    }
    
};
*/

// optimised time:O(5n) space:(5n)
class Solution {
public:
    vector<int> findPSE(const vector<int>& arr, int n) {
        // Finding previous smaller element (PSE) indices
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {  // Changed comparison to >=
                st.pop();
            }
            // If stack is empty, no smaller element found
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(const vector<int>& arr, int n) {
        // Finding next smaller element (NSE) indices
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {  // This comparison is correct
                st.pop();
            }
            // If stack is empty, no smaller element found
            if (st.empty()) {
                ans[i] = n; // Set to n to denote the end of the array
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int minimumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = findPSE(arr, n);
        vector<int> nse = findNSE(arr, n);
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            // Ensure all multiplication is under modulo
            total = (total + (1LL * right * left * arr[i]) % mod) % mod;
        }
        return total;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    int n = arr.size();
    cout << "Sum of subarray minimums: " << sol.minimumSum(arr) << endl;
    return 0;
}
