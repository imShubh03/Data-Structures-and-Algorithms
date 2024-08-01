#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    void levelOrderPrint(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If left or right child exists, add to queue
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);

                
                // Print the current node's data
                cout << node->data << " ";
            }
            cout << endl;  // Print a new line after each level
        }
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout<<"the level order traversal is..."<<endl;
    sol.levelOrderPrint(root);

    return 0;
}
