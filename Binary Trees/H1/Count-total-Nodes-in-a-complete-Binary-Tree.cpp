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
    void solve(TreeNode* node, int &cnt) {
        if (node == nullptr) return;
        cnt++;
        solve(node->left, cnt);
        solve(node->right, cnt);
    }

    int countNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};

// Driver Code
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.countNodes(root) << endl;

    return 0;
}
