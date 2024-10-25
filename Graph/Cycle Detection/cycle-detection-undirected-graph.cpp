#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int src, vector<int> adj[], int vis[]) {
        queue<pair<int, int>> q;
        vis[src] = 1;
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool detect(int v, vector<int> adj[]) {
        int vis[v] = {0};
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol;
    bool hasCycle = sol.detect(v, adj);
    if (hasCycle) {
        cout << "The graph contains a cycle\n";
    } else {
        cout << "The graph does not contain a cycle\n";
    }
    return 0;
}
