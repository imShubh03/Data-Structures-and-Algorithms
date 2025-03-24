#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;

        map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++)
            inMp[inorder[i]] = i;

        return solve(inorder, 0, inorder.size() - 1, inMp, 
                    postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd, 
                    map<int, int>& inMp, vector<int>& postorder, 
                    int poStart, int poEnd) {

        if (inStart > inEnd || poStart > poEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[poEnd]);

        int inRoot = inMp[postorder[poEnd]];
        int numsLeft = inRoot - inStart;

        root->left = solve(inorder, inStart, inRoot - 1, inMp,
                            postorder, poStart, poStart + numsLeft - 1);

        root->right = solve(inorder, inRoot + 1, inEnd, inMp,
                            postorder, poStart + numsLeft, poEnd - 1);

        return root;
    }
};

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    preorder(root); 
    return 0;
}
