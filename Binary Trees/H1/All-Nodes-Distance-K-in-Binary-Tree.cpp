#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    public:
    // Function to mark parent nodes for each node in the tree
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target) {
        // Create a queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // Get the current node from the queue
            TreeNode* curr = q.front();
            q.pop();

            // Store parent of left child
            if (curr->left) {
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }

            // Store parent of right child
            if (curr->right) {
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Map to store parent nodes of each node
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root, parentTrack, target); // Mark parent nodes

        // Map to track visited nodes
        unordered_map<TreeNode*, bool> vis;
        
        // Queue for BFS traversal
        queue<TreeNode*> q;

        // Start from the target node
        q.push(target);
        vis[target] = true;
        int currLevel = 0;

        // Perform BFS to traverse k levels
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // If k levels are traversed, break
            if (currLevel == k) break;
            currLevel++;

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* curr = q.front();
                q.pop();

                // Traverse left child if not visited
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                // Traverse right child if not visited
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                // Traverse parent node if not visited
                if (parentTrack[curr] && !vis[parentTrack[curr]]) {
                    q.push(parentTrack[curr]);
                    vis[parentTrack[curr]] = true;
                }
            }
        }

        // Store all nodes at distance k
        vector<int> res;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }

        return res;
    }
};
    

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* target = new TreeNode(5);

    int k;
    cin >> k;

    Solution sol;
    vector<int> ans = sol.distanceK(root, target, k);

    for (auto it : ans) {
        cout << it << endl;
    }

    return 0;
}
