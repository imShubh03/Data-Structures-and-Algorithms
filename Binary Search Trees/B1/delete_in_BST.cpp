#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) return helper(root);

        TreeNode* dummy = root;

        while (root != NULL) {
            if (key < root->val) { 
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else { 
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;  // **Fixed: Continue moving right**
                }
            }
        }

        return dummy;
    }
};

// Function to insert nodes into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// Function to print inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = NULL;

    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insertIntoBST(root, val);
    }

    int key;
    cin >> key;

    cout << "Before Deletion: ";
    inorder(root);
    cout << endl;

    root = sol.deleteNode(root, key);

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
