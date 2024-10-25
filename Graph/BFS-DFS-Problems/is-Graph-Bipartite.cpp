#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Depth-First Search (DFS) to check if the graph can be colored using two colors
    bool dfs(int node, int currentColor, vector<int> &color, vector<vector<int>> &adjList) {
        color[node] = currentColor; // Assign the current color to the node

        // Traverse all adjacent nodes
        for (auto neighbor : adjList[node]) {
            if (color[neighbor] == -1) { // If the neighbor is not colored
                // Recursively color the neighbor with the opposite color
                if (dfs(neighbor, !currentColor, color, adjList) == false) {
                    return false; // If the coloring fails, the graph is not bipartite
                }
            } else if (color[neighbor] == currentColor) {
                // If the neighbor has the same color as the current node, it's not bipartite
                return false;
            }
        }
        return true; // All connected nodes successfully colored
    }

public:
    // Function to check if the graph is bipartite
    bool isGraphBipartite(int vertices, int edges, vector<vector<int>> &adjList) {
        vector<int> color(vertices, -1); // Initialize colors for all vertices as -1 (uncolored)

        // Check all connected components in the graph
        for (int i = 0; i < vertices; i++) {
            if (color[i] == -1) { // If the vertex is not yet colored
                // Use DFS to color the component starting from vertex i
                if (dfs(i, 0, color, adjList) == false) {
                    return false; // If any component is not bipartite, return false
                }
            }
        }
        return true; 
    }
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges; 
    vector<vector<int>> adjList(vertices); 

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v; // Input edge between vertices u and v
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    Solution solution;
    // Check if the graph is bipartite
    bool isBipartite = solution.isGraphBipartite(vertices, edges, adjList);

    if (isBipartite) {
        cout << "The graph is bipartite\n";
    } else {
        cout << "The graph is not bipartite\n";
    }

    return 0;
}
