#include<bits/stdc++.h>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
    // Function to convert a binary tree into its mirror tree
    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }

        // Swap the left and right child of the current node
        swap(node->left, node->right);

        // Recursively call the mirror function for left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Utility function to perform level order traversal of the binary tree
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";
        
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Original Tree Level Order Traversal: ";
    levelOrderTraversal(root);
    
    // Create an instance of Solution and convert the tree to its mirror
    Solution obj;
    obj.mirror(root);
    
    cout << "Mirror Tree Level Order Traversal: ";
    levelOrderTraversal(root);
    
    return 0;
}
