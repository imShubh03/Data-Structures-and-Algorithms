#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;

    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

int successor(TreeNode* root, int key) {
    TreeNode* ans = NULL;

    while (root) {
        if (root->val > key) {
            ans = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans ? ans->val : -1;
}

int predecessor(TreeNode* root, int key) {
    TreeNode* ans = NULL;

    while (root) {
        if (root->val < key) {
            ans = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans ? ans->val : -1;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    int sucessor = successor(root, key);
    int precesor = predecessor(root, key);
    return {precesor, sucessor};
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);

    int key = 6;
    pair<int, int> ans = predecessorSuccessor(root, key);
    
    cout << "Predecessor: " << ans.first << ", Successor: " << ans.second;
    
    return 0;
}
