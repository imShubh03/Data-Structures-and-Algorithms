#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int isSumProperty(Node *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 1;

        int sum = 0;
        if (root->left) sum += root->left->data;
        if (root->right) sum += root->right->data;

        if (root->data == sum)
            return isSumProperty(root->left) && isSumProperty(root->right);

        return 0;
    }
};

// Driver Code
int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    Solution sol;
    if (sol.isSumProperty(root))
        cout << "The tree satisfies the Children Sum Property.\n";
    else
        cout << "The tree does NOT satisfy the Children Sum Property.\n";

    return 0;
}
