#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        data = v;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (root->data < val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->data == val) {
            return root;
        }
        if (root->data < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    Solution sol;
    TreeNode* root = NULL;

    root = sol.insertIntoBST(root, 5);
    root = sol.insertIntoBST(root, 3);
    root = sol.insertIntoBST(root, 8);
    root = sol.insertIntoBST(root, 2);
    root = sol.insertIntoBST(root, 4);
    root = sol.insertIntoBST(root, 6);
    root = sol.insertIntoBST(root, 9);

    cout << "Inorder Traversal: ";
    sol.inorder(root);
    cout << endl;

    int searchVal = 4;
    if (sol.searchBST(root, searchVal)) {
        cout << searchVal << " found in BST.\n";
    } else {
        cout << searchVal << " not found in BST.\n";
    }

    return 0;
}
