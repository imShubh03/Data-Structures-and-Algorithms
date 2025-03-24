#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd, 
                    unordered_map<int, int>& inMp) {
        
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMp[root->val];
        int leftSize = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inRoot - 1, inMp);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, inRoot + 1, inEnd, inMp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++)
            inMp[inorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMp);
    }
};

// Helper function to print inorder traversal
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    inorderPrint(root); 
    return 0;
}
