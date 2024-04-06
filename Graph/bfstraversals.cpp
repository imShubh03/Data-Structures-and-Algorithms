#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false); // Corrected vector size
        queue<int> q;
        // push starting node
        q.push(0);
        vis[0] = true;
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return ans; // Added return statement
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj = { {1,2,3},{4}, {5}, {},{},{}}; // Corrected adjacency list

    Solution sol;

    vector<int> result = sol.bfsTraversal(V, adj); // Corrected function call

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
