#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}

    BinaryTree(TreeNode *node) : root(node) {}

    void inOrder(TreeNode *root, vector<int> &temp) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, temp);
        temp.push_back(root->data);
        inOrder(root->right, temp);
    }

    void preOrder(TreeNode *root, vector<int> &temp) {
        if (root == nullptr) {
            return;
        }
        temp.push_back(root->data);
        preOrder(root->left, temp);
        preOrder(root->right, temp);
    }

    void postOrder(TreeNode *root, vector<int> &temp) {
        if (root == nullptr) {
            return;
        }
        postOrder(root->left, temp);
        postOrder(root->right, temp);
        temp.push_back(root->data);
    }

    vector<vector<int>> getTreeTraversal(TreeNode *root) {
        vector<vector<int>> ans;
        vector<int> temp;

        inOrder(root, temp);
        ans.push_back(temp);

        temp.clear();
        preOrder(root, temp);
        ans.push_back(temp);

        temp.clear();
        postOrder(root, temp);
        ans.push_back(temp);

        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BinaryTree tree(root);

    // Getting tree traversal results
    vector<vector<int>> traversals = tree.getTreeTraversal(tree.root);

    // Displaying the traversal results
    cout << "In-order traversal: ";
    for (int num : traversals[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Pre-order traversal: ";
    for (int num : traversals[1]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Post-order traversal: ";
    for (int num : traversals[2]) {
        cout << num << " ";
    }
    cout << endl;

    // Freeing memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
