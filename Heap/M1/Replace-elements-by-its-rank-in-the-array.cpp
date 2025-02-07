#include <bits/stdc++.h>
using namespace std;

/*TC:O(nlogn) SC:O(n)
class Solution{
    public:
    vector<int> replaceWithRank(vector<int>&arr, int n){
        vector<int>dummy = arr;

        sort(dummy.begin(), dummy.end());

        map<int,int>mp;
        int rank = 1;

        for(int i =0; i<n; i++){
            if(mp.count(dummy[i]) == 0){
                mp[dummy[i]] = rank;
                rank++;
            }
        }

        vector<int>res(n);

        for(int i =0; i<n; i++){
            res[i] = mp[arr[i]];
        }
        return res;
    }
};
*/

//TC:O(nlogn) SC:O(n)
class Solution{
    public:
    vector<int> replaceWithRank(vector<int>&arr, int n){
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i =0; i<n; i++){
            pq.push(arr[i]);
        }
        unordered_map<int, int>mp;
        int rank  =1;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();

            if(mp.count(top) == 0){
                mp[top]= rank;
                rank++;
            }
        }
        vector<int>res;
        for(int i =0; i<n; i++){
            res[i] = mp[arr[i]];
        }

        return res;
    }
};

int main() {
    
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    vector<int>ans = sol.replaceWithRank(arr, n);

    for(int i =0; i<n; i++){
        cout<<ans[i] << " ";
    }

    return 0;
}