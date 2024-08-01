#include <iostream>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a tree node
    TreeNode(int d) {
        data = d;
        left = right = nullptr;
    }
};

// In-order Traversal (Left, Root, Right)
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-order Traversal (Root, Left, Right)
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order Traversal (Left, Right, Root)
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    // Create individual nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Perform pre-order traversal
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Perform post-order traversal
    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
