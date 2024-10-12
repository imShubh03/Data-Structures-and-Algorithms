#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
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

    vector<int> res = bfs(V, adj);
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
