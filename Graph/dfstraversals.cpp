#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, vector<int>& ans) {
        vis[node] = true;
        ans.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        int start = 0;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
    }
};

int main() {
    int V = 6;
    vector<int> adj[V] = { {1,2,3},{4}, {5}, {},{},{}}; // Corrected adjacency list

    Solution sol;

    vector<int> result = sol.dfsOfGraph(V, adj); // Corrected function call

    // Print the DFS traversal result
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
