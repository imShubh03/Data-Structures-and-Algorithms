#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int>&vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>> &isConnected){
        int n = isConnected.size();
        // convert to adj list
        vector<int>adj[n];
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i =0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>>isConnected(n, vector<int>(n));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>isConnected[i][j];
        }
    }

    Solution sol;
    int ans = sol.findCircleNum(isConnected);
    cout<<ans<<endl;


    return 0;
}