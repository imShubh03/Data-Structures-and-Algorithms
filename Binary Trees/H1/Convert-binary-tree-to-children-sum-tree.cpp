#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void changeToChildrenSumtree(TreeNode* root) {
        if (!root) return;
        
        int childSum = 0;
        if (root->left) childSum += root->left->val;
        if (root->right) childSum += root->right->val;
        
        if (childSum >= root->val)
            root->val = childSum;
        else {
            if (root->left) root->left->val = root->val;
            if (root->right) root->right->val = root->val;
        }

        changeToChildrenSumtree(root->left);
        changeToChildrenSumtree(root->right);

        int total = 0;
        if (root->left) total += root->left->val;
        if (root->right) total += root->right->val;
        
        if (root->left || root->right)
            root->val = total;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    sol.changeToChildrenSumtree(root);

    inorder(root);
    cout << endl;

    return 0;
}
