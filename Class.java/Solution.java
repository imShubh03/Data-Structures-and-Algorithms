import java.util.*;

public class Solution {
    public List<Integer> bfsTraversal(int V, List<List<Integer>> adj) {
        boolean[] visited = new boolean[V]; // Visited array to track visited nodes
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> result = new ArrayList<>();

        // Start BFS from node 0
        queue.offer(0);
        visited[0] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node); // Add current node to the result list

            // Traverse all adjacent nodes of the current node
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark neighbor as visited
                    queue.offer(neighbor); // Add neighbor to the queue
                }
            }
        }

        return result; // Return the BFS traversal result
    }

    public static void main(String[] args) {
        int V = 6; // Number of vertices
        List<List<Integer>> adj = new ArrayList<>();

        // Initialize adjacency list
        adj.add(Arrays.asList(1, 2, 3)); // Node 0's neighbors: 1, 2, 3
        adj.add(Collections.singletonList(4)); // Node 1's neighbor: 4
        adj.add(Collections.singletonList(5)); // Node 2's neighbor: 5
        adj.add(Collections.emptyList()); // Node 3 has no neighbors
        adj.add(Collections.emptyList()); // Node 4 has no neighbors
        adj.add(Collections.emptyList()); // Node 5 has no neighbors

        Solution sol = new Solution();
        List<Integer> result = sol.bfsTraversal(V, adj); // Perform BFS traversal

        // Print the BFS traversal result
        System.out.print("BFS Traversal: ");
        for (int node : result) {
            System.out.print(node + " ");
        }
        System.out.println();
    }
}
