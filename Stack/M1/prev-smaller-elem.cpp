#include<bits/stdc++.h>
using namespace std;
/*
vector<int> prevSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}
*/

// optimised 

vector<int> prevSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};  // Example input
    vector<int> result = prevSmallerElement(arr);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
