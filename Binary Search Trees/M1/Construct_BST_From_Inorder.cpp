#include<bits/stdc++.h>
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

/*
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) { // If root is NULL, create a new node
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            insertIntoBST(root, preorder[i]);
        }
        return root;
    }

};
*/


class Solution {
    public:
    TreeNode* solve(vector<int>&preorder, int &i, int bound, int n){
        if(i == n || preorder[i] > bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root -> left = solve(preorder, i, root -> val, n);
        root -> right = solve(preorder, i, bound, n);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int i =0;
        return solve(preorder, i, INT_MAX, n);
    }
};


void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    TreeNode* root = sol.bstFromPreorder(preorder);
    
    inorder(root);
    
    return 0;
}
