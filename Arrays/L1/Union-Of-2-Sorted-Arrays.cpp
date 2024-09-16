#include <bits/stdc++.h>
using namespace std;

/* brute time:O(n log(size)) + O(mlog(size)) O(n+m)   space:O(n+m){set} + O(n+m){only to return ans}
vector<int> findUnion(int arr1[], int n, int arr2[], int m){
    set<int>st;
    for(int i =0; i<n; i++){
        st.insert(arr1[i]);
    }
    for(int i =0; i<m; i++){
        st.insert(arr2[i]);
    }
    int size = st.size();
    vector<int>ans(size);
    int i =0;
    for(auto it : st){
        ans[i] = it;
        i++;
    }
    return ans;
}
*/

// optimal : time:O(n+m) space:O(n+m){to return ans}
vector<int> findUnion(int arr1[], int n, int arr2[], int m){
    vector<int>ans;
    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(ans.empty() || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(ans.empty() || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(ans.empty() || ans.back() != arr1[i]){
            ans.push_back(arr1[i]); 
        }
        i++;
    }
    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}


int main() {
    int n, m;
    cin>>n>>m;

    int arr1[n], arr2[m];

    for(int i =0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }

    vector<int>res = findUnion(arr1, n, arr2, m);

    for(auto it: res){
        cout<<it<<" ";
    }

    return 0;
}