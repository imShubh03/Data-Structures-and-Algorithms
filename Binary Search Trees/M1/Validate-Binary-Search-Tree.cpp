#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool solve(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal) return false;

        return solve(root->left, minVal, root->val) && solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "Valid BST\n";
    } else {
        cout << "Not a valid BST\n";
    }

    return 0;
}
