#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        int floor = -1;
        while (root) {
            if (root->data == x) {
                return root->data;
            }
            if (root->data > x) {
                root = root->left;
            } else {
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
    }

    int ceil(Node* root, int x) {
        int ceil = -1;
        while (root) {
            if (root->data == x) {
                return root->data;
            }
            if (root->data < x) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};

// Function to insert a node into BST
Node* insertIntoBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    Solution sol;
    Node* root = NULL;
    vector<int> values = {10, 5, 15, 3, 7, 18}; 
    
    for (int val : values) {
        root = insertIntoBST(root, val);
    }

    int x;
    cin >> x;

    cout << "Floor: " << sol.floor(root, x) << endl;
    cout << "Ceil: " << sol.ceil(root, x) << endl;

    return 0;
}
