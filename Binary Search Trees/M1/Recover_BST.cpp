#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

/*
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    void fixBST(TreeNode* root, vector<int>& sortedNodes, int &index) {
        if (!root) return;
        fixBST(root->left, sortedNodes, index);
        root->val = sortedNodes[index++];
        fixBST(root->right, sortedNodes, index);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        sort(nodes.begin(), nodes.end());
        int index = 0;
        fixBST(root, nodes, index);
    }
};
*/


class Solution {
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        // If the previous node's value is greater than the current node, it's a violation
        if (prev && (prev->val > root->val)) {
            // First violation: store first (larger value) and middle (smaller value)
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            // Second violation: store the last node (smaller value found later)
            else {
                last = root; // Mark this as the second misplaced node
            }
        }
        prev = root; // Update prev to current node

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        // If two non-adjacent nodes were swapped, swap first and last
        if (first && last)
            swap(first->val, last->val);
        // If adjacent nodes were swapped, swap first and middle
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
    


void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2); // Swapped nodes: 2 and 3

    cout << "Before Fix: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After Fix: ";
    printInorder(root);
    cout << endl;

    return 0;
}
