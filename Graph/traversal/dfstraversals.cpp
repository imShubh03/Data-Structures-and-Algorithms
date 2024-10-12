#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& ans) {
    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, ans);
        }
    }
}
vector<int> performDFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> ans;
    dfs(0, vis, adj, ans); // Start DFS from node 0
    return ans;
}

void createAdjList(int V, int E, vector<pair<int, int>>& edges, vector<int> adj[]) {
    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> adj[V];
    createAdjList(V, E, edges, adj);

    vector<int> res = performDFS(V, adj);
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
