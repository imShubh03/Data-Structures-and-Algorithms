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
int main() {
    // Create individual nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
    // The tree looks like this:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    */
    
    cout << "Binary Tree created." << endl;

    return 0;
}
