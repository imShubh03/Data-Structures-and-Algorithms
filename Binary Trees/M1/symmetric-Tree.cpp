#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool solve(TreeNode* leftN, TreeNode* rightN) {
        if (leftN == nullptr || rightN == nullptr) {
            return leftN == rightN;
        }
        if (leftN->val != rightN->val) {
            return false;
        }
        return solve(leftN->left, rightN->right) && solve(leftN->right, rightN->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return solve(root->left, root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}
